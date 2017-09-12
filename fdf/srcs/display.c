/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/12 18:21:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
** Write the pixel in the mage
*/

void	px_img(t_base *base, int x, int y, int color)
{
		//ft_putendlcolor("px2img()", MAGENTA);
	if (x > base->win_x || x < 0 || y >= base->win_y || y < 0)
		return ;
	base->data[y * base->win_x + x] = color;
	//ft_putnbrendl(y * base->win_x + x);

}

/*
** Init the lines values and start the line() needed
*/

void	start_line(t_base *base)
{
			//ft_putendlcolor("line2()", MAGENTA);
	int	xx;
	int	yy;
		// ft_putstr("xi = ");
		// ft_putnbrendl(base->xi);
		// ft_putstr("yi = ");
		// ft_putnbrendl(base->yi);
		// ft_putstr("xj = ");
		// ft_putnbrendl(base->xj);
		// ft_putstr("yj = ");
		// ft_putnbrendl(base->yj);
	//base->xi *= base->interval;
	//base->yi *= base->interval;
	//base->xj *= base->interval;
	//base->yj *= base->interval;
	base->x = base->xi;
	base->y = base->yi;
	base->dx = base->xj - base->xi;
	base->dy = base->yj - base->yi;
	xx = (base->dx > 0) ? 1 : -1;
	yy = (base->dy > 0) ? 1 : -1;
	base->dx = abs(base->dx);
	base->dy = abs(base->dy);
	px_img(base, base->x, base->y, base->color);
	if (base->dx > base->dy)
		line1(base, xx, yy);
	else
		line2(base, xx, yy);
}

void line1(t_base *base, int xx, int yy) 
{
			//ft_putendlcolor("line1()", MAGENTA);
	int	i;
	int cumul;

	i = 1;
	cumul = base->dx / 2;
	while (i <= base->dx)
	{
		base->x += xx;
		cumul += base->dy;
		if (cumul >= base->dx)
		{
			cumul -= base->dx;
			base->y += yy;
		}
		px_img(base, base->x, base->y, base->color);
		i++;
	}
}

void	line2(t_base *base, int xx, int yy)
{
			//ft_putendlcolor("line2()", MAGENTA);
	int	i;
	int cumul;

	i = 1;
	cumul = base->dy / 2;
	while (i <= base->dy)
	{
		base->y += yy;
		cumul += base->dx;
		if (cumul >= base->dy) 
		{
			cumul -= base->dy;
			base->x += xx;
		}
		px_img(base, base->x, base->y, base->color);
		i++;
	}
}

void	draw_hori(t_base *base)
{
			//ft_putendlcolor("draw_hori()", MAGENTA);
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < base->d.y - 1)
	{
		x = 0;
		while (x < base->d.x)
		{
			base->xi = x;
			base->yi = y;
			base->xj = x + 1;
			base->yj = y + 1;
			get_color(base, base->d.z[i]);
			conv_iso(base, 0, base->d.z, i);
			if (x + 1 <= base->d.x)
				start_line(base);
			i++;
			x++;
		}
		y++;
	}
}

void	draw_verti(t_base *base)
{
			//ft_putendlcolor("draw_verti()", MAGENTA);
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < base->d.y)
	{
		x = 0;
		while (x < base->d.x)
		{
			base->xi = x;
			base->yi = y;
			base->xj = x + 1;
			base->yj = y + 1;
			get_color(base, base->d.z[i]);
			conv_iso(base, 1, base->d.z, i);
			if (x + 1 < base->d.x)
				start_line(base);
			i++;
			x++;
		}
		y++;
	}
	draw_hori(base);
}

/*
void	draw(t_base *base)
{
			ft_putendlcolor("draw()", MAGENTA);
	int		x;
	int		y;
	int		i;
	int		nbi;

	i = 0;
	y = 1;
	nbi = base->xi;
	while (y <= base->d.y)
	{
		x = 1;
		while (x < base->d.x)
		{
			base->xi = nbi;
			base->xj = nbi + 1;
			if (x + 1 <= base->d.x)
			{
			//	conv_xy(base, base->d.z[i]);
				//conv_iso(base, x, y, i, 1);
				line(base, get_color(base, base->d.z[i]));
			}
			if (y + 1 <= base->d.y)
			{
			//	conv_xy(base, base->d.z[i]);
				//conv_iso(base, x, y, i, 0);
				line(base, get_color(base, base->d.z[i]));
			}
			i++;
			//conv_iso(base, x * base->interval, y * base->interval, base->d.z[i]);
			//line(base, get_color(base, base->d.z[i++]));
			base->xi++;
			base->xj++;
			x++;
		}
		base->yi++;
		base->yj++;
		y++;
	}
	//draw2(base);
}
*/
