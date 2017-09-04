/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/04 20:15:18 by vmercadi         ###   ########.fr       */
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
	px_img(base, &disp);
	mlx_put_image_to_window(base->data, base->win, base->img, 0, 0);
}

// /*
// ** Write in the image (kind of pixel_put for image)
// */

// void	px_img(t_base *base, t_disp *disp)
// {
// 			ft_putendlcolor("px_img()", MAGENTA);	
// 	int		x;
// 	int		y;
// 	int		i;
//
// 	disp->ofs = 0;
// 	y = 1;
// 	i = 0;
// 	while (y <= base->d.y)
// 	{
// 		x = 1;
// 		while (x <= base->d.x)
// 		{
// 				ft_putstr("z0 = ");
// 				ft_putnbrendl(base->d.z[i]);
// 			disp->color = get_color(base, base->d.z[i]);
// 			// disp->color = green_gradiant(base, base->d.z[i]); 
// 				ft_putendl("preyo");
// 			base->data[y * base->win_x * (base->interval) + x * base->interval] = disp->color;
// 			x++;
// 			i++;
// 		}
// 		y++;
// 	}
// 			ft_putendl("end px");
// }


void	px_img(t_base *base, t_disp *disp)
{
			ft_putendlcolor("px_img()", MAGENTA);	
	int		x;
	int		y;
	int		i;

	disp->ofs = 0;
	y = 1;
	i = 0;
	while (y <= base->d.y)
	{
		x = 1;
		while (x <= base->d.x)
		{
				ft_putstr("z0 = ");
				ft_putnbrendl(base->d.z[i]);
			disp->color = get_color(base, base->d.z[i]);
			// disp->color = green_gradiant(base, base->d.z[i]); 
				ft_putendl("preyo");
			conv_iso(base, x , y, base->d.z[i]);
			base->data[base->d.y2 * base->win_x * base->interval + base->d.x2 * base->interval] = disp->color;
			x++;
			i++;
		}
		y++;
	}
			ft_putendl("end px");
}


/*
void	px_img(t_base *base, int i, int x, int y)
{
			ft_putendlcolor("px_img()", MAGENTA);	
	unsigned int color;

	color = get_color(base, base->d.z[i]); 
	base->data[y * base->win_x * (base->interval) + x * base->interval] = color;
}
*/
