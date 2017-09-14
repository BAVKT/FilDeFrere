/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:44:22 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/14 20:30:10 by vmercadi         ###   ########.fr       */
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
	base->win_x = 2000;
	base->win_y = 1200;
	base->alt = 2;
	base->view.vx = 0.4;
	base->view.vy = 0.2;
	base->view.zoom = base->d.x * base->d.y > 5000 ? 10 : 30;
	base->win_size = base->win_x * base->win_y;
	base->bpp = 0;
	base->endian = 0;
	base->sizeline = base->win_y;
	base->mlx = NULL;
	base->mlx = mlx_init();
	base->win = NULL;
	base->win = mlx_new_window(base->mlx, base->win_x, base->win_y, "Fdf");
	base->img = NULL;
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = NULL;
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
	fd = open(base->av, O_RDONLY);
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
	fd = open(base->av, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
		j = get_z(base, str, j);
	base->d.z[j] = 0;
	close(fd);
}
