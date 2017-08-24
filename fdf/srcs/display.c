/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/24 22:17:37 by vmercadi         ###   ########.fr       */
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
	base->data = (int *)mlx_get_data_addr(base->img, &disp.bpp, &disp.sizeline, &disp.endian);
	px_img(base, &disp);
	mlx_put_image_to_window(base->data, base->win, base->img, 0, 0);
}

/*
** Return the color of the pixel
*/

/*
int		get_color(t_base *base, t_disp *disp)
{
			ft_putendlcolor("get_color()", MAGENTA);	
  	int c1;
  	int c2;
  	int c3;

 	c1 = (disp.img_color & 0xFF000000) >> 24;
 	c2 = (disp.img_color & 0xFF0000) >> 16;
 	c3 = (disp.img_color & 0xFF00) >> 8;
	if ()
		return (0);
	else
		return ();
}
*/

/*
** Write in the image (kind of pixel_put)
*/
void	px_img(t_base *base, t_disp *disp)
{
			ft_putendlcolor("get_px()", MAGENTA);	
	int		x;
	int		y;
	int		n;

	disp->ofs = 0;
	y = 0;
	n = 0;
	while (y < base->d.y)
	{
		x = 0;
		while (x < base->d.x)
		{
			//disp->img_color = mlx_get_color_value(base->mlx, disp->color);
			if (base->d.z[n + y] != 0)
			{
				base->data[y * base->win_y * base->win_y / base->d.y + x * base->win_x / base->d.x] = 0xFFFFFF;
					ft_putnbrendl(y * base->win_y * base->win_y / base->d.y + x * base->win_x / base->d.x);
			}
			x++;
			n++;
		}
		y++;
	}
}

//############################################################################################
//############################################################################################
//############################################################################################
// pixels[y * width + x] = color

// /*
// **Troisieme test d'affichage.
// */

// void 	affpoints(void *win, void *mlx, int *countxy)
// {
// 	ft_putendl("affpoints");
// 	int x;
// 	int y;
// 	int i;
// 	int j;
// 	int k;
// 	float interval;

// 	i = 0;
// 	interval = 20;
// 	while (i < countxy[0])
// 	{
// 		j = 0;
// 		while (j < countxy[1])
// 		{
// 			k = g_D2.x[i];
// 			while (k++ < g_D2.x[i + 1])
// 				mlx_pixel_put(mlx, win, g_D2.x[i] * interval, g_D2.y[j] * interval, 0x00FFFFFF);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// /*
// ** Link the points together
// */

// void	ft_trace()
// {
// 	ft_putendl("ft_trace");
// 	int i;
// 	int h;

// 	i = 0;
// 	h = g_A.interval;
// 	while (i <= g_A.size)
// 	{
// 		ft_putendl("BONJOUR");
// 		ft_ligne(g_D2.x[i] * h, g_D2.y[i] * h, g_D2.x[i + 1] * h, g_D2.y[i + 1] * h);
// 		i++;
// 	}
// }






// /*
// // 1
// void	ft_trace(int size, int interval, void *mlx, void *win)
// {
// 	int x;
// 	int y;
// 	int i;
// 	double a;
// 	double b;

// 	i = 0;
// 	while (i <= size)
// 	{
// 		a = (double)(g_D2.y[i + 1] - g_D2.y[i])/(g_D2.x[i + 1] - g_D2.x[i]);
// 		b = g_D2.y[i] - a * g_D2.x[i];
// 		x = g_D2.x[i];
// 		y = (int)(a * x + b);
// 		mlx_pixel_put(mlx, win, x * interval, y * interval, 0x00FFFFFF);		
// 		i++;
// 	}
// }
// */
