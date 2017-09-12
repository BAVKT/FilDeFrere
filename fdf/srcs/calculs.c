/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:43:13 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/12 14:05:41 by vmercadi         ###   ########.fr       */
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
	for(i, loop through rows)
	for(j, loop through columns)
    x = j * tile width
    y = i * tile height
    tileType = levelData[i][j]
    placetile(tileType, twoDToIso(new Point(x, y)))

}
*/
/*
// Iso David
void			get_pos(t_base *base, int i)
{
	base->xi *= base->interval;
	base->yi *= base->interval;
	base->xj *= base->interval;
	base->yj *= base->interval;
	base->xi = (base->view.zoom * (base->xi - base->yi) + (base->win_x / 2)) / 100;
	base->yi = (base->view.zoom * (base->xi + base->yi) - base->d.z[i] + (base->win_y / 4)) / 100;
	base->xj = (base->view.zoom * (base->xj - base->yj) + (base->win_x / 2)) / 100;
	base->yj = (base->view.zoom * (base->xj + base->yj) - base->d.z[i] + (base->win_y / 4)) / 100;
}
*/
// Iso jerem
void	conv_iso(t_base *base, int n, int *z, int i)
{
		// ft_putendl("i");
		// ft_putnbrendl(base->xi);
		// ft_putnbrendl(base->yi);
		// ft_putendl("j");
		// ft_putnbrendl(base->xi);
		// ft_putnbrendl(base->yi);
	//i = z[i];
	base->x = base->xi - base->d.x / 2;
	base->y = base->yi - base->d.y / 2;
	base->xi = base->view.vx * (base->x - base->y) * base->view.zoom;
	base->yi = base->view.vy * (base->x + base->y) * base->view.zoom;
			// ft_putstr("z = ");
			// ft_putnbrendl(z[i] * base->interval);
			// ft_putstr("int = ");
			// ft_putnbrendl(z[i] * base->interval);	
			// ft_putstr("z + int = ");
			// ft_putnbrendl(z[i] * base->interval);
	base->yi -= z[i] * base->interval;
	if (n)
	{
		base->xj = base->view.vx * ((base->x + 1) - base->y) * base->view.zoom;
		base->yj = base->view.vy * ((base->x + 1) + base->y) * base->view.zoom;
		base->yj -= z[i + 1] * base->interval;
	}
	else
	{
		base->xj = base->view.vx * (base->x - (base->y + 1)) * base->view.zoom;
		base->yj = base->view.vy * (base->x + (base->y + 1)) * base->view.zoom;
		base->yj -= z[i + base->d.x] * base->interval;
	}
	base->xi += base->win_x / 2 - base->d.x / 2;
	base->xj += base->win_x / 2 - base->d.x / 2;
	base->yi += base->win_y / 2 - base->d.y / 2;
	base->yj += base->win_y / 2 - base->d.y / 2;
		// ft_putendl("i2");
		// ft_putnbrendl(base->xi);
		// ft_putnbrendl(base->yi);
		// ft_putendl("j2");
		// ft_putnbrendl(base->xi);
		// ft_putnbrendl(base->yi);
}

// Iso net
// void	conv_iso(t_base *base, int x, int y)
// {
// 	//int half;
// 	int xx;
// 	int yy;
// 	xx = x + 1;
// 	yy = y + 1;
// /*
// 	x *= base->interval;
// 	y *= base->interval;
// 	base->xi = x - y;
// 	base->yi = (x + y) / 2;
// 	base->xi = xx - yy;
// 	base->yi = (xx + yy) / 2;
//  */
// 	x = base->d.x / 2;
//  	base->xi = (2 * y + x) / 2;
//  	base->yi = (2 * y - x) / 2;
//  	base->xj = (2 * yy + xx) / 2;
//  	base->yj = (2 * yy - xx) / 2;
// 	base->xi *= base->interval;
// 	base->yi *= base->interval;
// 	base->xj *= base->interval;
// 	base->yj *= base->interval;

/*
// Iso qmundata
void		get_pos(t_base *base, int i)
{
	int xx;
	int yy; 

	base->x = base->xi * base->interval;
	base->y = base->yi * base->interval;
	base->xi = base->x - base->y + (base->win_x * 0.5);
	base->yi = -base->d.z[i] + (base->x * 0.5) + (base->y * 0.5) + (base->win_y * 0.3);
	base->xj = xx - yy + (base->win_x * 0.5);
	base->yj = -base->d.z[i] + (xx * 0.5) + (yy * 0.5) + (base->win_y * 0.3);
	
	// else if (win->opt == PARA)
	// {
	// 	pt->d2x = rp->px - rp->pz + WIN_W * 0.5;
	// 	pt->d2y = rp->py + -1 * 0.5 * rp->pz + WIN_H * 0.3;

}
*/
/*
// projection yolo
void	get_pos(t_base *base, int i)
{
	base->xi = (base->win_x / 2) - (base->xi * base->interval) - base->d.z[i];
	base->yi *= base->interval / 2 - base->d.z[i];
	base->xi = (base->win_x / 2) - (base->xi + 1 * base->interval) - base->d.z[i];
	base->yi++;
	base->yi *= base->interval / 2 - base->d.z[i];
}
*/

 
//  /*
// 	half = base->interval / 2;
// 	base->xi = (x - y) * base->interval;
// 	base->yi = (x + y) * base->interval;

// 	base->xj = (x + 1 - y + 1) * base->interval;
// 	base->yj = (x  + 1 + y + 1) * base->interval;
// */
// }
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
