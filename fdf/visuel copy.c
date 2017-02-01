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

#include "fdf.h"
#include <stdio.h>

//Fonction a retrecir.
//Sert a compter le nombre de lignes et de caracteres (win_x && win_y)
int 	*ft_count_xy(char *buf, int fd, int *nblc)
{
	ft_putendl("countxy");
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

//Fuionner les 2 voir les 3 et utiliser ft_range 
//Rempli le tableau de valeurs D3 en x et renvoi le tableau rempli.
float 	*ft_rempx(int x, int y, t_D3 D3)
{
	ft_putendl("rempx");
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	j = 0;
	k = 1;
	while (j <= x * y)
	{
		if (k == x + 1)
			k = 1;
		D3.x[i++] = k++;
		j++;
	}
	return(D3.x);
}

//Rempli le tableau en y
float 	*ft_rempy(int y, int x, t_D3 D3)
{
	ft_putendl("rempy");
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	j = 0;
	k = 1;
	while (j <= y * x)
	{
		if (k == y + 1)
			k = 1;
		D3.y[i++] = k++;
		j++;
	}
	return(D3.y);
}

//Permet de récupérer le Z en 3D
float 	*ft_rempz(char *buf, int fd, t_D3 D3)
{
	ft_putendl("rempz");
	int 	end;
	char 	**tabc;		//Le retour de strsplit, double tableau de char
	int 	i;
	int 	j;

	j = 0;
	while ((end = read(fd, buf, SIZE)) > 0)
	{
		i = 0;
		buf[end] = '\0';
		tabc = ft_strsplit((const char *)buf, ' ');			
		while (tabc[i])
			D3.z[j++] = ft_atoi(tabc[i++]); 	//On converti le resultat dans le tableau.
	}
	return(D3.z);
}

//Retourne un tableau avec la conversion des donnees 3D en 2D
t_D2 	conv_xy(int *countxy, t_D3 D3, t_D2 D2)
{
	ft_putendl("convxy");
	int 	i;
	float 	cte;

	i = 0;
	cte = 0.7;
	while (i < countxy[0] * countxy[1])
	{
		D2.x[i] = (D3.x[i] + cte * D3.z[i]);
		D2.y[i] = (D3.y[i] + (cte/2) * D3.z[i]);
		i++;
	}
	return (D2);
}

//Initialise les tableaux pour recuperer et convertir et remplir le tableau final en 2D.
//countxy[0] = win_x && countxy[1] = win_y
t_D2 ft_def(int *countxy, char *buf, int fd)
{
	ft_putendl("ft_def");
	t_D3 	D3;
	t_D2 	D2;

	D2.x = (float *)malloc(sizeof(float) * countxy[0]);
	D2.y = (float *)malloc(sizeof(float) * countxy[1]);
	D3.x = (float *)malloc(sizeof(float) * countxy[0]);
	D3.y = (float *)malloc(sizeof(float) * countxy[1]);
	D3.z = (float *)malloc(sizeof(float) * (countxy[1] * countxy[0]));
	D3.x = ft_rempx(countxy[0], countxy[1], D3);
	D3.y = ft_rempy(countxy[1], countxy[0], D3);
	D3.z = ft_rempz(buf, fd, D3);
	D2 = conv_xy(countxy, D3, D2);
	close(fd);
	return (D2);
}


/*
//Deuxieme test d'affichage qui ne marche pas.
void 	affpoints(void *win, void *mlx, int *countxy, t_D2 D2)
{
	ft_putendl("affpoints");
	int x;
	int y;
	int i;
	int j;
	int interval;

	i = 0;
	j = 0;
	interval = 20;
	x = 0;
	while (x < countxy[0] * interval)
	{
		y = 0;
		j = 0;
		while (y < countxy[1] * interval)
		{
			ft_putstr("D2.x = ");
			ft_putnbrendl(D2.x[i]);
			ft_putstr(" - D2.y = ");
			ft_putnbrendl(D2.y[j]);
			mlx_pixel_put(mlx, win, D2.x[i] * interval, D2.y[j] * interval, 0x00FFFFFF);
			y+=interval;
			j++;
		}
		x+=interval;
		i++;
	}
	i = 0;
	j = 0;
	y = 0;
	while (y < countxy[1] * interval)
	{
		x = 0;
		i = 0;
		while (x < countxy[0] * interval)
		{
			mlx_pixel_put(mlx, win, D2.x[i++] * interval, D2.y[j++] * interval, 0x00FFFFFF);
			x+=interval;
		}
		y+=interval;
	}

}*/

//Troisieme test d'affichage.
void 	affpoints(void *win, void *mlx, int *countxy, t_D2 D2)
{
	ft_putendl("affpoints");
	int x;
	int y;
	int i;
	int j;
	float interval;

	i = 0;
	interval = 20;
	while (i < countxy[0])
	{
		j = 0;
		while (j < countxy[1])
		{
			mlx_pixel_put(mlx, win, D2.x[i] * interval, D2.y[j] * interval, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

//Lance la fenetre et l'affichage
void 	initvisu(int *countxy, t_D2 D2)
{
	ft_putendl("initvisu");
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, (countxy[0] * 100)/2, (countxy[1] * 100)/2, "Fil de fer");
	affpoints(win, mlx, countxy, D2);	
	mlx_loop(mlx);													//On attend des evenements
}

void 	initcalcul(char *arg)
{
	ft_putendl("initcalcul");
	int 	*countxy;
	int 	*nblc;
	int		fd;
	char	buf[SIZE + 1];
	t_D2 	D2;

	nblc = (int *)malloc(sizeof(int) * 2);
	nblc[0] = 0;
	nblc[1] = 0;
	fd = open(arg, O_RDONLY);
	countxy = ft_count_xy(buf, fd, nblc);
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
