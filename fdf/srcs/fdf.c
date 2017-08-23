/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/23 15:10:56 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fdf(t_base *base)
{
			ft_putendlcolor("FDF()", MAGENTA);
	mlx_loop(base->mlx);
}

int 	main(int ac, char **av)
{
	t_base	base;

	if (ac > 2)
		error_parse(1);
	else if (ac < 2)
		error_parse(2);
	if (!ft_strcmp(av[1], "usage"))
		error_parse(-1);
	base.av = av[1];
	check_file(base.av);
	base = init_base(&base);
	fdf(&base);
	return (0);
}
