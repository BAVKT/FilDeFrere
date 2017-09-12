/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:44:22 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/12 17:13:06 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Init the base and view struct
*/

t_base	init_base(t_base *base)
{
			ft_putendlcolor("init_base()", MAGENTA);
	base->zmax = 0;
	base->zmin = 0;
	init_d(base);
	base->size = base->d.x * base->d.y;
	base->xi = 0;
	base->yi = 0;
	base->xj = 1;
	base->yj = 1;
	base->win_x = 2000;
	base->win_y = 1200;
	base->alt = 7;
	base->view.vx = 0.4;
	base->view.vy = 0.2;
	base->interval = (base->win_x * base->win_y) / ((base->d.x * 10) * (base->d.y * 10));
	if (base->interval > 200)
		base->interval /= (base->interval / 2);
			ft_putnbrendl(base->d.x);
			ft_putnbrendl(base->d.y);
			ft_putnbrendl(base->interval);
	//base->interval = get_interval(base);
	base->win_size = base->win_x * base->win_y;
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, base->win_x, base->win_y, "Phil 2 frer");
	base->img = (int *)malloc(sizeof(int) * base->win_size);
	base->view.zoom = 2;
	return (*base);
}

/*
** Init the t_d with all the x/y basic values
*/

void		init_d(t_base *base)
{
			ft_putendlcolor("init_d()", MAGENTA);
	char	*str;
	int		fd;
	int		j;

	base->d.x = 0;
	base->d.y = 0;
	str = ft_strnew(0);
	fd = open(base->av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		get_xy(base, str);
		free(str);
	}
	close(fd);
	base->size = base->d.x * base->d.y;
	base->d.z = (int *)malloc(sizeof(int) * base->size);
	j = 0;
	fd = open(base->av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
		j = get_z(base, str, j); //+free() a ajouter
		base->d.z[j] = 0;
	close(fd);
}

/*
** Init the display struct
*/

t_disp		init_display(t_base *base)
{
			ft_putendlcolor("init_display()", MAGENTA);
	t_disp	disp;

	disp.ofs = 0;
	disp.endian = 0;
	disp.sizeline = base->win_y;
	disp.bpp = 0;
	return (disp);
}

/*
** Start and fill the image
*/

void	init_image(t_base *base)
{
			ft_putendlcolor("image()", MAGENTA);
	t_disp	disp;

	disp = init_display(base);
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = (int*)mlx_get_data_addr(base->img, &disp.bpp, &disp.sizeline, &disp.endian);
}


//############################################################################################
//############################################################################################
//############################################################################################





// /*
// ** Initialise les tableaux pour recuperer et convertir et remplir le tableau final en 2D.
// */
// //countxy[0] = win_x && countxy[1] = win_y

// void 	ft_def(int *countxy, char *buf, int fd)
// {
// 	ft_putendl("ft_def");
// 	float 	size;

// 	size = countxy[0] * countxy[1];
// 	g_D2.x = (float *)malloc(sizeof(float) * g_A.size);
// 	g_D2.y = (float *)malloc(sizeof(float) * g_A.size);
// 	g_D3.x = (float *)malloc(sizeof(float) * g_A.size);
// 	g_D3.y = (float *)malloc(sizeof(float) * g_A.size);
// 	g_D3.z = (float *)malloc(sizeof(float) * g_A.size);
// 	g_A.size = size;
// 	close(fd);
// }

// /*
// ** Start the windows and display
// */

// void 	initvisu(int *countxy)
// {
// 	ft_putendl("initvisu");

// 	g_A.interval = 20;
// 	g_A.mlx = mlx_init();
// 	g_A.win = mlx_new_window(g_A.mlx, (countxy[0] * 100)/2, (countxy[1] * 100)/2, "Fil de fer");
// 	ft_trace();
// 	mlx_loop(g_A.mlx);													//On attend des evenements
// }

// /*
// ** Init all the basics values
// */

// void 	initcalcul(char *arg)
// {
// 	ft_putendl("initcalcul");
// 	int 	*countxy;
// 	int 	*nblc;
// 	int		fd;
// 	char	buf[SIZE + 1];

// 	nblc = (int *)malloc(sizeof(int) * 2);
// 	nblc[0] = 0;
// 	nblc[1] = 0;
// 	fd = open(arg, O_RDONLY);
// 	countxy = ft_count_xy(buf, fd, nblc);
// 	close(fd);
// 	fd = open(arg, O_RDONLY);
// 	ft_def(countxy, buf, fd);
// 	close(fd);
// 	ft_rempx(countxy[0], countxy[1]);
// 	ft_rempy(countxy[1], countxy[0]);
// 	fd = open(arg, O_RDONLY);
// 	ft_rempz(buf, fd);
// 	close(fd);
// 	ft_conv_xy(countxy);
// 	initvisu(countxy);
// }