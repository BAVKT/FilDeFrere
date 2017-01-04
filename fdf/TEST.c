
// TEST POUR VOIR SI CA REND LES BONS NOMBRES 
////

#include "mlx.h"
#include "libft.h"
#include <sys/types.h>		//Les Headers nécéssaire
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 42

//============================================================================================
//********************************************************************************************
//============================================================================================

void    ft_putchar(char c)      //en p1, le caractere a afficher
{
    write(1, &c, 1);            //p1 = sortie standard, p2 = le caractere, p3 = la taille.
}

void	ft_putstr(char *str)		//en p1, un tableau
{
	int index;

	index = 0;
	while (str[index] != '\0')		//Tant que le contenu de la case du tsableau n'est pas \0
	{
		ft_putchar(str[index]);		//On affiche le caractere correspondant a la case 
		index++;
	}
}

void    ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);

	ft_putchar((nb % 10) + '0');

}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		signe;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] < 33 && str[i] > 0)
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return ((int)(nb * signe));
}

static int		ft_count(char const *s, char c)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		nb++;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char		*ft_cp(char const *s, char c, int *i)
{
	int		a;
	char	*s2;

	a = 0;
	s2 = (char *)malloc(sizeof(s2) * (ft_strlen(s)) + 1);
	if (!s2)
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		s2[a] = s[*i];
		a++;
		*i += 1;
	}
	s2[a] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		nb;
	char	**s2;

	i = 0;
	j = 0;
	nb = ft_count(s, c);
	if (!s || !c)
		return (NULL);
	s2 = (char **)malloc(sizeof(s) * (nb + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (j < nb && s[i])
		{
			s2[j] = ft_cp(s, c, &i);
			j++;
		}
		s2[j] = NULL;
	}
	return (s2);
}

void ft_printabint(int *tabint, char *phrase, char *NomTest, int taille)
{
	int i;

	i = 0;
	ft_putstr(NomTest);
	ft_putchar('\n');
	while (i < taille)
	{
		ft_putstr(phrase);
		ft_putnbr(tabint[i]);
		ft_putchar('\n');
		i++;
	}
}

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
int 	*ft_countxy(char *buf, int fd, int *nblc)
{
	ft_putstr("ft_count_xy\n");
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


//NE MAR CHE PAS SUR CERTAINES MAP COMME PENTENEGPOS
//Permet de récupérer le Z en 3D
int 	*ft_rempz(char *buf, int fd, t_D3 D3)
{
	ft_putstr("rempz\n");
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
	ft_putstr("conv_xy\n");
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
	ft_putstr("ft_def\n");
	t_view	V;
	t_D3 	D3;
	t_D2 	D2;

	D2.x = (int *)malloc(sizeof(int) * countxy[0]);
	D2.y = (int *)malloc(sizeof(int) * countxy[1]);
	D3.x = (int *)malloc(sizeof(int) * countxy[0]);
	D3.y = (int *)malloc(sizeof(int) * countxy[1]);
	D3.z = (int *)malloc(sizeof(int) * (countxy[1] * countxy[0]));
	V.x = countxy[0] / 2;
	V.y = countxy[1] / 2;
	V.z = 1000;
	ft_printabint(countxy, "countxy[] = ", "COUNTXY", 2);
	D3.x = ft_rempx(countxy[0], D3);
	ft_printabint(D3.x, "D3.x[i] = ", "def D3.x", countxy[0]);
	D3.y = ft_rempy(countxy[1], D3);
	ft_printabint(D3.y, "D3.y[i] = ", "def D3.y", countxy[1]);
	D3.z = ft_rempz(buf, fd, D3);
	close(fd);
	ft_printabint(D3.z, "D3.z[i] = ", "def D3.z", countxy[0] * countxy[1]);
	D2 = conv_xy(countxy, D3, D2, V);
	return (D2);
}

//TEST A SUPPRIMER POUR AFFICHER LES POITNS CONVERTIS.
void 	affpoints(void *win, void *mlx, int *countxy, t_D2 D2)
{
	ft_putstr("affpoints\n");
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
		ft_putstr("initvisu\n");
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, countxy[0], countxy[1], "Fil de fer");
	affpoints(win, mlx, countxy, D2);
	mlx_loop(mlx);													//On attend des evenements
}

void 	initcalcul(char *arg)
{
		ft_putstr("initcalcul\n");
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




