/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 22:58:03 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <sys/types.h>		//Les Headers nécéssaire
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 42

//Les coordonees du point de vue. Le x et y correspondent aux tailles de la fenettre divisé par deux 
//et le z represente la distance approximative entre nous et l'ecran. On va dire 1000.
typedef struct 	s_view
{
	int 		x;
	int 		y;
	int 		z;
}				t_view;
//Les coordonees D3 donc recuperees avec les autres fonctions
typedef struct 	s_D3
{
	int 		*x;
	int 		*y;
	int 		*z;
}				t_D3;

//La conversion des donees D3 en donnees D2.
typedef struct 	s_D2
{
	int 		*x;
	int 		*y;
} 				t_D2;

//Fonction a retrecir.
//Sert a compter le nombre de lignes et de caracteres (win_x && win_y)
int 	*ft_count_xy(char *buf, int fd, int *nblc)
{
	int i;
	int end;

	while ((end = read(fd, buf, SIZE)))
	{
		buf[end] = '\0';
		i = 0;
		while (buf[i])
		{
			while (buf[i] && buf[i] == ' ')
				i++;
			while (buf[i] && buf[i] != ' ' && buf[i] != '\n')
				i++;
			while (buf[i] && buf[i] == ' ')
				i++;
			if (buf[i] == '\n')
			{
				i++;
				nblc[1]++;
			}
			nblc[0]++;
		}
	}
	nblc[0] = nblc[0]/nblc[1];
	return (nblc);
}

//Rempli le tableau de valeurs D3 en x et renvoi le tableau rempli.
int 	*ft_rempx(char x, t_D3 D3)
{
	ft_putstr("rempx\n");
	int 	i;
	int 	j;

	i = 0;
	j = 1;
	while (j <= x)
		D3.x[i++] = j++;
	return(D3.x);
}

//Rempli le tableau en y
int 	*ft_rempy(int y, t_D3 D3)
{
	ft_putstr("rempy\n");
	int 	i;
	int 	j;

	i = 0;
	j = 1;
	while (j <= y)
		D3.y[i++] = j++;
	return(D3.y);
}

//Permet de récupérer le Z en 3D
int 	*ft_rempz(char *buf, int fd, t_D3 D3)
{
	int 	end;
	char 	**tabc;		//Le retour de strsplit, double tableau de char
	int 	i;
	int 	j;

	j = 0;
	while ((end = read(fd, buf, SIZE)))
	{
		i = 0;
		buf[end] = '\0';
		tabc = ft_strsplit((const char *)buf, ' ');
		while (tabc[i])
			D3.z[j++] = ft_atoi(tabc[i++]); 		//On converti le resultat dans le tableau.
	}
	return(D3.z);
}

//Retourne un tableau avec la conversion des donnees 3D en 2D
t_D2 	conv_xy(int *countxy, t_D3 D3, t_D2 D2, t_view V)
{
	int i;

	i = 0;
	while (i < D3.x[countxy[0]])
	{
		D2.x[i] = (V.z * (D3.x[i] - V.x) / (V.z + D3.z[i]) + V.x);
		i++;
	}
	i = 0;
	while (i < D3.y[countxy[1]])
	{
		D2.y[i] = (V.z * (D3.y[i] - V.y) / (V.z + D3.z[i]) + V.y);
		i++;
	}
	return (D2);
}


//Initialise les tableaux pour recuperer et convertir et remplir le tableau final en 2D.
//countxy[0] = win_x && countxy[1] = win_y
t_D2 ft_def(int *countxy, char *buf, int fd)
{
	t_view	V;
	t_D3 	D3;
	t_D2 	D2;
	int 	fd2;

	fd2 = fd;
	D2.x = (int *)malloc(sizeof(int) * countxy[0]);
	D2.y = (int *)malloc(sizeof(int) * countxy[1]);
	D3.x = (int *)malloc(sizeof(int) * countxy[0]);
	D3.y = (int *)malloc(sizeof(int) * countxy[1]);
	D3.z = (int *)malloc(sizeof(int) * (countxy[1] * countxy[0]));
	V.x = countxy[0] / 2;
	V.y = countxy[1] / 2;
	V.z = 1000;
	D3.x = ft_rempx(buf, fd, D3);
	close(fd);
	fd = fd2;
	D3.y = ft_rempy(buf, fd, D3);
	close(fd);
	fd = fd2;
	D3.z = ft_rempz(buf, fd, D3);
	close(fd);
	D2 = conv_xy(countxy, D3, D2, V);
	return (D2);
}

//TEST A SUPPRIMER POUR AFFICHER LES POITNS CONVERTIS.
void 	affpoints(void *win, void *mlx, int *countxy, t_D2 D2)
{
	int x;
	int y;
	int interval;

	interval = 50;
	x = interval;
	while (x < countxy[1] * countxy[0])
	{
		y = interval;
		while (y < (countxy[1] * countxy[0]) - interval)
		{
			mlx_pixel_put(mlx, win, D2.x[x], D2.y[y], 0x00FFFFFF);
			y+=interval;
		}
		x+=interval;
	}
	y = interval;
	while (y < countxy[1] * countxy[0])
	{
		x = interval;
		while (x < (countxy[1] * countxy[0]) - interval)
		{
			mlx_pixel_put(mlx, win, D2.x[x], D2.y[y], 0x00FFFFFF);
			x+=interval;
		}
		y+=interval;
	}
}

//Lance la fenetre et l'ffichage
//reste a determiner le calcul qui donne la taille de la fenetre
//Et faire en sorte de mettre un scroll si c'est trop grand
//Ou mettre une taille de fenetre de base en dur et automatiquement metre du scroll.
void 	initvisu(int *countxy, t_D2 D2)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, countxy[0], countxy[1], "Fil de fer");
	affpoints(win, mlx, countxy, D2);
	mlx_loop(mlx);													//On attend des evenements
}

void 	initcalcul(char *arg)
{
	int 	*countxy;
	int 	*nblc;
	int		fd;
	char	buf[SIZE + 1];
	t_D2 	D2;

	nblc = (int *)malloc(sizeof(int) * 2);
	nblc[0] = 0;
	nblc[1] = 0;
	fd = open(arg, O_RDONLY);
	countxy = ft_countxy(buf, fd, nblc);
	close(fd);
	fd = open(arg, O_RDONLY);
	D2 = ft_def(countxy, buf, fd);
	close(fd);
	initvisu(countxy, D2);
}

int 	main(int argc, char **argv)
{
	if (argc == 2)
		initcalcul(argv[1]);
	else
		ft_putstr("Mauvais nombre de fichiers passés");
	return (0);
}


/*
//La fonction pour ouvrir la fenetre et tracer la grille
void	trace_grille(void *win, void *mlx, int *wintab, int *tabi) 	//Faut utiliser tabi pour donenr les vraies valeurs
{
	int 	y;
	int 	x;
	int 	interval;
	int 	i;

	i = tabi[0];	//juste pour utilsier tabi
	i = 0;
	interval = 50; 				//Rien ne s'affiche si on passe pas une valeur en dur.
	y = interval;
	while (y < wintab[1] * wintab[2]) 	//La taille de base de win_y
	{
		x = interval;
		while (x < (wintab[0] * wintab[2]) - interval)					//JE vois pas trop quels calculs faire avec tabi
			mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
		y+=interval;
	}
	i = 0;
	x = interval;
	while (x < wintab[0] * wintab[2])
	{
		y = interval;
		while (y < (wintab[1] * wintab[2]) - interval)
			mlx_pixel_put(mlx, win, x, y++, 0x00DA57BC);
		x+=interval;
	}
}
*/
//###########################################################################################
//AUTRE
//###########################################################################################
/*

#proteger le retour de mlx_init(); Commande :
env -i <votre-executable> 			S’il plante, c’est que vous ne l’avez pas bien protégé 😉

◦ open
◦ read
◦ write
◦ close
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit
◦ Toutes les fonctions de la lib math (-lm et man 3 math)
◦ Toutes les fonctions de la miniLibX.

*/
