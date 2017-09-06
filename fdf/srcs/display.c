/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/06 18:20:09 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Start and fill the image
*/

void	image(t_base *base)
{
			ft_putendlcolor("image()", MAGENTA);
	t_disp	disp;

	disp = init_display(base);
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = (int*)mlx_get_data_addr(base->img, &disp.bpp, &disp.sizeline, &disp.endian);
}

/*
** Write the pixel in the mage
*/

void	px_img(t_base *base, int x, int y, int color)
{
		//ft_putendlcolor("px2img()", MAGENTA);
	if (x > base->win_x || x < 0 || y > base->win_y || y < 0)
		return ;
	base->data[y * base->win_y + x] = color;
}

/*
** Draw the lines between the 2 points 
*/

void	line(t_base *base, int color)
{
			ft_putendlcolor("line()", MAGENTA);
	int	dx;
	int	dy;
	int	cumul;

	base->x = base->xi;
	base->y = base->yi;
	dx = base->xj - base->xi;
	dy = base->yj - base->yi;
	px_img(base, base->x, base->y, color);
	cumul = dx / 2;
	base->x = base->xi + 1;
	while (base->x <= base->xj)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			base->y += 1;
		}
		px_img(base, base->x, base->y, color);
		base->x++;
	}
}

/*
** Draw the map
*/

void	draw(t_base *base)
{
			ft_putendlcolor("draw()", MAGENTA);
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 1;
	while (y <= base->d.y)
	{
		x = 1;
		while (x <= base->d.x)
		{

			base->xi = x;
			base->yi = y;
			if (x + 1 < base->d.x)
			{
				conv_iso(base, x, y, i, 1);
				line(base, get_color(base, base->d.z[i]));
			}
			if (y + 1 < base->d.y)
			{
				conv_iso(base, x, y, i, 0);
				line(base, get_color(base, base->d.z[i]));
			}
			i++;
			//conv_iso(base, x * base->interval, y * base->interval, base->d.z[i]);
			//line(base, get_color(base, base->d.z[i++]));
			//base->xi++;
			//base->yi++;
			//base->xj++;
			//base->yj++;
			x++;
		}
		y++;
	}
}

/*
** OLD px
*/

// void	px_img(t_base *base, t_disp *disp)
// {
			// ft_putendlcolor("px_img()", MAGENTA);	
	// int		x;
	// int		y;
	// int		i;
// 
	// disp->ofs = 0;
	// y = 1;
	// i = 0;
	// while (y <= base->d.y)
	// {
		// x = 1;
		// while (x <= base->d.x)
		// {
				// ft_putstr("z0 = ");
				// ft_putnbrendl(base->d.z[i]);
			// disp->color = get_color(base, base->d.z[i]);
			//disp->color = green_gradiant(base, base->d.z[i]); 
				// ft_putendl("preyo");
			// conv_iso(base, x , y, base->d.z[i]);
			// base->data[base->d.y2 * base->win_x * base->interval + base->d.x2 * base->interval] = disp->color;
			// x++;
			// i++;
		// }
		// y++;
	// }
			// ft_putendl("end px");
// }
// 
