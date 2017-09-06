/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:43:13 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/06 18:36:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Convert the 2D values in 3D values
*/
/*
void 	conv_xy(t_base *base)
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

void 	conv_iso(t_base *base, int x, int y, int i, int n)
{
			ft_putendlcolor("conv_iso()", MAGENTA);
	int		xx;
	int		yy;
	int		a;

	a = 7;
	xx = x - base->d.x / 2;
	yy = y - base->d.y / 2;
	base->xi = base->view.vx * (xx - yy) * base->view.zoom;
	base->yi = base->view.vy * (xx + yy) * base->view.zoom;
	base->yi -= base->d.z[i] * a;
	if (n)
	{
		base->xj = base->view.vx * ((xx + 1) - yy) * base->view.zoom;
		base->yj = base->view.vy * ((xx + 1) + yy) * base->view.zoom;
		base->yj -= base->d.z[i + 1] * a;
	}
	else
	{
		base->xj = base->view.vx * (xx - (yy + 1)) * base->view.zoom;
		base->yj = base->view.vy * (xx + (yy + 1)) * base->view.zoom;
		base->yj -= base->d.z[i] * a;
	}
	base->xi += base->win_x / 2 - base->d.x / 2;
	base->xj += base->win_x / 2 - base->d.x / 2;
	base->yi += base->win_y / 2 - base->d.y / 2;
	base->yj += base->win_y / 2 - base->d.y / 2;

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
}


void	conv_para(t_base *base, int x, int y, int z)
{
			ft_putendlcolor("conv_para()", MAGENTA);
	double cte1;

	cte1 = 0.8;
	base->xi = x + cte1 * z;
	base->yi = y + cte1 / 2 * z;
}
