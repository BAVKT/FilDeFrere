/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:22:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/11 16:59:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Return the pixel color
*/

void		get_color(t_base *base, int z)
{
			//ft_putendlcolor("get_color()", MAGENTA);
	unsigned int	color;

	if (z > 0)
		color = 0xffffff;
	if (!base->av[2])
		color = 0xffffff;//get_gradiant(base, z, 0xffffff);
	color = (ft_strequ(base->av[2], "yellow") ? get_gradiant(base, z, 0xffff00) : color);
	color = (ft_strequ(base->av[2], "red") ? get_gradiant(base, z, 0xff0000) : color);
	color = (ft_strequ(base->av[2], "blue") ? get_gradiant(base, z, 0x000fff) : color);
	color = (ft_strequ(base->av[2], "cyan") ? get_gradiant(base, z, 0x00ffff) : color);
	color = (ft_strequ(base->av[2], "green") ? get_gradiant(base, z, 0x00ff00) : color);
	color = (ft_strequ(base->av[2], "white") ? get_gradiant(base, z, 0xffffff) : color);
	color = (ft_strequ(base->av[2], "purple") ? get_gradiant(base, z, 0xAA00FF) : color);
	color = (ft_strequ(base->av[2], "rainbow") ? get_gradiant(base, z, 0x9933ff) : color);
	base->color = color;
}

/*
** Return a beautiful gradient
*/

int		get_gradiant(t_base *base, int z, unsigned int color)
{
			//ft_putendlcolor("get_radiant()", MAGENTA);
	if (z == 0)
		return (color);
		color = color * z / base->zmax;
	return (color);
}
