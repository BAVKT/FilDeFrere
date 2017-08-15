/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:44:22 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:52:08 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Init the base and view struct
*/

t_base	init_base(t_base *base)
{
			ft_putendlcolor("init_base()", MAGENTA);
	base->view.vx = base->size[0];
	base->view.vy = base->size[0];
	base->view.vz = 1000;
	base->interval = 20;
	init_d(base);
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, 1000, 1000, "Fil de fer");
	return (*base);
}

/*
** Init the t_d with all the x/y basic AND converted values 
*/

void		init_d(t_base *base)
{
			ft_putendlcolor("init_d()", MAGENTA);
	char	*str;
	int		fd;

	str = ft_strnew(0);
	fd = open(base->av, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		get_xyz(&base->d, str);
		free(str);
	}
	close(fd);
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