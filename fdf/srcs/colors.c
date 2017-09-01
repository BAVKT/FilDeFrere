/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:22:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/01 16:49:05 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Return the pixel color
*/

int		get_color(t_base *base, int z)
{
			ft_putendlcolor("get_color()", MAGENTA);
	unsigned int	color;

		ft_putendl(base->av[2]);
		ft_putstr("z1 = ");
		ft_putnbrendl(z);
		color = 0;
	color = (ft_strequ(base->av[2], "yellow") ? get_gradiant(base, z, 0xffff00) : color);
	color = (ft_strequ(base->av[2], "red") ? get_gradiant(base, z, 0xff0000) : color);
	color = (ft_strequ(base->av[2], "blue") ? get_gradiant(base, z, 0x000fff) : color);
	color = (ft_strequ(base->av[2], "cyan") ? get_gradiant(base, z, 0x00ffff) : color);
	color = (ft_strequ(base->av[2], "green") ? get_gradiant(base, z, 0x00ff00) : color);
	color = (ft_strequ(base->av[2], "white") ? get_gradiant(base, z, 0xffffff) : color);
	color = (ft_strequ(base->av[2], "purple") ? get_gradiant(base, z, 0xAA00FF) : color);
	color = (ft_strequ(base->av[2], "rainbow") ? get_gradiant(base, z, 0x9933ff) : color);
	return (color);
}

/*
** Return a beautiful green gradient
*/

int		green_gradiant(t_base *base, int z)
{
	unsigned int	color;

			ft_putstr("z666 = ");
			ft_putnbrendl(z);
	if (base->zmax == 0)
		return (0x00ff00);
	color = 0x00ff00 * z / base->zmax;
	return (color);
}
/*
** Return a beautiful blue gradient
*/

int		blue_gradiant(t_base *base, int z)
{
	unsigned int	color;

	if (base->zmax == 0)
		return (0x00ffff);
	color = 0x00ffff * z / base->zmax;
	return (color | (color >> 8));
}

/*
** Return a beautiful gradient
*/

int		get_gradiant(t_base *base, int z, unsigned int color)
{
			ft_putendlcolor("get_radiant()", MAGENTA);
			ft_putstr("bli1 = ");
			ft_putnbrendl(color);
			ft_putstr("z = ");
			ft_putnbrendl(z);
	if (z == 0)
		return (color);
//	else if (z > 0)
		color = color * z / base->zmax;
	//else if (z < 0 && base->zmin != 0)
	//	color = color * z / base->zmin;
	return (color);
}
