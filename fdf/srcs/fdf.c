/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:16:35 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fdf(t_base *base)
{
	mlx_loop(base->mlx);
}

int 	main(int ac, char **av)
{
	t_base	base;

	if (ac > 2)
		error_parse(1);
	else if (ac < 2)
		error_parse(2);
	check_file(av[1]);
	base = init_base(&base);
	fdf(&base);
	return (0);
}