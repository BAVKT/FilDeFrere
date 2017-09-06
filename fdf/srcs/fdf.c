/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/06 16:46:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fdf(t_base *base)
{
			ft_putendlcolor("FDF()", MAGENTA);
	draw(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	mlx_hook(base->win, 2, 0, event, base);
	mlx_loop(base->mlx);
}

int 	main(int ac, char **av)
{
	t_base	base;

	if (ac > 3)
		error_parse(1);
	else if (ac < 2)
		error_parse(2);
	if (!ft_strcmp(av[1], "usage"))
		error_parse(-1);
	base.av = (char **)malloc(sizeof(char *) * ac - 1);
	base.av = ft_cp_tab(base.av, av);
	check_file(base.av[1]);
	base = init_base(&base);
	image(&base);
	fdf(&base);
	return (0);
}
