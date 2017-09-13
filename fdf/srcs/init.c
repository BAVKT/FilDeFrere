/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:44:22 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/13 21:28:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Init the base and view structs
*/

t_base	init_base(t_base *base)
{
	base->zmax = 0;
	base->zmin = 0;
	init_d(base);
	if (!base->d.x || !base->d.y)
		error(3);
	base->size = base->d.x * base->d.y;
	base->win_x = 2000;
	base->win_y = 1200;
	base->alt = 2;
	base->view.vx = 0.4;
	base->view.vy = 0.2;
	base->view.zoom = 2;
	base->win_size = base->win_x * base->win_y;
	base->bpp = 0;
	base->endian = 0;
	base->sizeline = base->win_y;
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, base->win_x, base->win_y, "Fdf");
	base->img = (int *)malloc(sizeof(int) * base->win_size);
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = (int*)mlx_get_data_addr(
			base->img, &base->bpp, &base->sizeline, &base->endian);
	return (*base);
}

/*
** Init the t_d with all the x/y basic values
*/

void	init_d(t_base *base)
{
	char	*str;
	int		fd;
	int		j;
	int		ok;

	base->d.x = 0;
	base->d.y = 0;
	str = ft_strnew(0);
	fd = open(base->av[1], O_RDONLY);
	while ((ok = get_next_line(fd, &str)) > 0)
	{
		get_xy(base, str);
		free(str);
	}
	if (ok == -1)
		error(5);
	close(fd);
	base->size = base->d.x * base->d.y;
	base->d.z = (int *)malloc(sizeof(int) * base->size);
	j = 0;
	fd = open(base->av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
		j = get_z(base, str, j);
	base->d.z[j] = 0;
	close(fd);
}
