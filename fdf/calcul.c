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
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>		//Les Headers nécéssaire
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 42
#include <unistd.h>

//####################################################################################
//Fonctions de libft
//####################################################################################
void    ft_putchar(char c)      //en p1, le caractere a afficher
{
	write(1, &c, 1);            //p1 = sortie standard, p2 = le caractere, p3 = la taille.
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

//###########################################################################################
//Taille de la fenetre
//###########################################################################################

//Sert a compter la taille maximum en x(max caracteres sur une ligne) et la taille en y (nb de lignes);
//Pour la taille de la fenetre a ouvrir entre autre ou alors faut qu'on puisse scroll dans la fenetre
//Le but est de lire le fichier pour connaitre le nb de lignes et de colonnes.
int 	*ft_count_xy(char *arg, char *buf,  int fd, int *nblc)
{
	int 	l;			//lignes
	int 	c;			//caracteres
	int 	i;
	int 	end;
	char	buf[SIZE + 1];
	int		fd;
	int 	*nblc; 		//nblc[0] = Nombre de caracteres && nblc[1] = Nombre de lignes

	l = 0;
	c = 0;
	while ((end = read(fd, buf, SIZE)))
	{
		buf[end] = '\0';
		i = 0;
		while (buf[i])
		{	
			if (buf[i] == '\n')			
			{
				nblc[0] = (c > nblc[0]) ? c : nblc[0];		//si c > a nblc[0] alors nblc[0] = nblc[0] 
				nblc[1] = l++;
				c = 0;
				i++;
			}
			while (buf[i] <= '9' && buf[i] >= '0' && buf[i])
				i++;
			while (buf[i] == ' ')
				i++;
			c++;
		}
	}
	nblc[0] = (c > nblc[0]) ? c : nblc[0];		//
	nblc[1] = l++;
	return (nblc);
}

//Met toutes les valeurs dans le tableau pour pouvoir les utiliser facilement dans l'affichage
int 	*ft_tab_val(char *arg, char *buf, int fd, int *countxy)
{
	int 	end;
	char 	**tabc;		//Le retour de strsplit, double tableau de char
	int 	*tabi; 		//Le tableau a retourner une fois la conversion fini
	int 	i;
	int 	j;
	char	buf[SIZE + 1];
	int		fd;

	j = 0;
	tabi = (int *)malloc(sizeof(int) * (countxy[0] * countxy[1]));
	while ((end = read(fd, buf, SIZE)))
	{
		i = 0;
		buf[end] = '\0';
		tabc = ft_strsplit((const char *)buf, ' ');
		while (tabc[i])
			tabi[j++] = ft_atoi(tabc[i++]); 		//On converti le resultat dans le tableau.
	}
	return (tabi);
}

//La fonction pour ouvrir la fenetre et tracer la grille
void	trace_grille(void *mlx, int win_x, int win_y, int *tabi) 	//Faut utiliser tabi pour donenr les vraies valeurs
{
	void	*win;
	int 	y;
	int 	x;
	int 	interval;
	int 	i;

	i = 0;
	interval = 50; 				//Rien ne s'affiche si on passe pas uen valeur en dur.
	win = mlx_new_window(mlx, win_x, win_y, "Fil de fer");
	y = interval;
	while (y < win_y)
	{
		x = interval;
		while (x < win_x - interval)					//JE vois pas trop quels calculs faire avec tabi
			mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
		y+=interval;
	}
	i = 0;
	x = interval;
	while (x < win_x)
	{
		y = interval;
		while (y < win_y - interval)
			mlx_pixel_put(mlx, win, x, y++, 0x00DA57BC);
		x+=interval;
	}
}

//Le main test
void 	init(char *arg)
{
	void	*mlx;

	int 	*nblc; 		//nblc[0] = Nombre de caracteres && nblc[1] = Nombre de lignes
	int 	*countxy;
	int 	*tabi;

	mlx = mlx_init();
	nblc = (int *)malloc(sizeof(int) * 2);
	nblc[0] = 0;
	nblc[1] = 0;
	fd = open(arg, O_RDONLY);										//On r2cupere le fd pour les fonctions
	countxy = ft_count_xy(arg, buf, fd, nblc);  					//On recupere les tailles de lignes et caracteres
	tabi = ft_tab_val(arg, buf, fd, countxy);						//On recupere le tableau avec les valeurs
	trace_grille(mlx, countxy[0] * 100, countxy[1] * 100, tabi); 	//On affiche la grille 
	mlx_loop(mlx);													//On attend des evenements
}

int 	main(int argc, char **argv)
{

	if (argc == 2)
		init(argv[1]);
	else
		ft_putchar('X');
}


/*
//###########################################################################################
//TEST
//###########################################################################################
int	main()
{
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	int 	win_x; 		//Largeur de la fenetre
	int 	win_y;		//hauteur de la fenetre
	int 	interval;	//Defini la taille des carrés de la grille


	interval = 50;
	win_x = 1100;
	win_y = win_x;
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_x, win_y, "Fil de fer");
	y = interval;
	while (y < win_y)
	{
		x = interval;
		while (x < win_x - interval)
		{
			mlx_pixel_put(mlx, win, x + ft_atoi(tab), y, 0x00AFAFFC);
			x++;
		}
		y+=interval;
	}
	x = interval;
	while (x < win_x)
	{
		y = interval;
		while (y < win_y - interval)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00BEFAFF);
			y++;
		}
		x+=interval;
	}
	mlx_loop(mlx);
}

*/

/*
//###########################################################################################
// main de test pour ft_count_xy
//###########################################################################################
int main(int argc, char **argv)
{
	int 	*countxy;
	char	buf[SIZE + 1];
	int		fd;
	int 	*nblc; 		//nblc[0] = Nombre de caracteres && nblc[1] = Nombre de lignes

	if (argc == 12)
		argc = 12;
	nblc = (int *)malloc(sizeof(int) * 2);
	nblc[0] = 0;
	nblc[1] = 0;
	fd = open(argv[1], O_RDONLY);
	countxy = ft_count_xy(argv[1], buf, fd, nblc);
	ft_putnbr(countxy[0]);
	ft_putchar('\n');
	ft_putnbr(countxy[1]);
	return (0);
}
*/

//###########################################################################################
//Permet d'afficher une grille
//###########################################################################################
/*
int	main()
{
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;
	int 	win_x; 		//Largeur de la fenetre
	int 	win_y;		//hauteur de la fenetre
	int 	interval;	//Defini la taille des carrés de la grille

	interval = 50;
	win_x = 1100;
	win_y = win_x;
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_x, win_y, "Fil de fer");
	y = interval;
	while (y < win_y)
	{
		x = interval;
		while (x < win_x - interval)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y+=interval;
	}
	x = interval;
	while (x < win_x)
	{
		y = interval;
		while (y < win_y - interval)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x+=interval;
	}
	mlx_loop(mlx);
}
*/



/* 
//###########################################################################################
//code de base pour ouvrir une fenetre avec pixel
//###########################################################################################
int	main()
int	main()
{
	void	*mlx;
	void	*win;
	int 	x;
	int 	y;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 1200, "Fil de fer");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
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
