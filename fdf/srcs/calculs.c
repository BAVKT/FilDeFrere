/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:43:13 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/08 16:25:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Convert the 2D values in 3D values
*/
/*
void 	conv_xy(t_base *base, int z)
{
			ft_putendlcolor("conv_xy()", MAGENTA);
	
	int 	i;
	float 	cte;

	i = 0;
	cte = 0.789;
	while (i < (base->d.x * base->d.y))
	{
		base->d.x2[i] = (base->d.x[i] + cte * base->d.z[i]);
		base->d.y2[i] = (base->d.y[i] + (cte/2) * base->d.z[i]);
		i++;
	}


}
*/

void	conv_iso(t_base *base, int x, int y)
{
	int half;

	half = base->interval / 2;
	base->xi *= base->interval;
	base->yi *= base->interval;
	base->xi = (x - y) * half;
	base->yi = (x + y) * half;

	base->xi = base->xi + 1;
	base->xj = base->xj + 1;
	base->xj *= base->interval;
	base->yj *= base->interval;
	base->xj = (x - y) * half;
	base->yj = (x + y) * half;
}
/*
// Basic isometric map to screen is:
screen.x = (map.x - map.y) * TILE_WIDTH_HALF;
screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;

// Solve the first equation for map.x
screen.x == (map.x - map.y) * TILE_WIDTH_HALF
screen.x / TILE_WIDTH_HALF == map.x - map.y8
map.x == screen.x / TILE_WIDTH_HALF + map.y

// Solve the second equation for map.y
screen.y == (map.x + map.y) * TILE_HEIGHT_HALF
screen.y / TILE_HEIGHT_HALF == map.x + map.y
map.y == screen.y / TILE_HEIGHT_HALF - map.x

// Replace "map.y" in the first equation with what it equals in the second
map.x == screen.x / TILE_WIDTH_HALF + map.y
map.x == screen.x / TILE_WIDTH_HALF + screen.y / TILE_HEIGHT_HALF - map.x
2(map.x) == screen.x / TILE_WIDTH_HALF + screen.y / TILE_HEIGHT_HALF
map.x == (screen.x / TILE_WIDTH_HALF + screen.y / TILE_HEIGHT_HALF) /2

// And now do the same for map.y
map.y == screen.y / TILE_HEIGHT_HALF - (screen.x / TILE_WIDTH_HALF + map.y)
map.y == screen.y / TILE_HEIGHT_HALF -(screen.x / TILE_WIDTH_HALF) - map.y
2(map.y) == screen.y / TILE_HEIGHT_HALF -(screen.x / TILE_WIDTH_HALF)
map.y == (screen.y / TILE_HEIGHT_HALF -(screen.x / TILE_WIDTH_HALF)) /2

// So final actual commands are:
map.x = (screen.x / TILE_WIDTH_HALF + screen.y / TILE_HEIGHT_HALF) /2;
map.y = (screen.y / TILE_HEIGHT_HALF -(screen.x / TILE_WIDTH_HALF)) /2;
*/

/*	double cte1;
	double cte2;

	cte1 = 0.6;
	cte2 = 0.7;
	x++;
	y++;
	z++;

	base->xi = cte1 * x - cte2 * y;
	base->yi = z + cte1 / 2 * x + cte2 / 2 * y;
	base->xj = cte1 * (x + 1) - cte2 * (y + 1);
	base->yi = z + cte1 / 2 * (x + 1) + cte2 / 2 * (y + 1);
*/

void	conv_para(t_base *base, int x, int y, int z)
{
			ft_putendlcolor("conv_para()", MAGENTA);
	double cte1;

	cte1 = 0.8;
	base->xi = x + cte1 * z;
	base->yi = y + cte1 / 2 * z;
}
