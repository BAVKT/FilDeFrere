/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:15:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"













//############################################################################################
//############################################################################################
//############################################################################################


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
