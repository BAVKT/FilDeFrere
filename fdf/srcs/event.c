/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:07:14 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/12 14:00:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** move position of the map
*/

void	move(int k, t_base *base)
{
			ft_putendlcolor("move()", MAGENTA);
				ft_putnbrendl(k);
	if (k == 0)
		base->xi -= (base->xi <= 0 ? 0 : 1);	
	else if (k == 1)
		base->yi +=	(base->yi >= base->win_y ? 0 : 1);
	else if (k == 2)
		base->xi +=	(base->xi >= base->win_x ? 0 : 1);
	else if (k == 13)
		base->yi -= (base->yi <= 0 ? 0 : 1);
	else if (k == 123)
		base->xj -=	(base->xj <= 0 ? 0 : 1);
	else if (k == 124)
		base->xj += (base->xj >= base->win_x ? 0 : 1);
	else if (k == 125)
	{

		base->view.zoom--;		
				ft_putnbrendl(base->view.zoom);
	//	base->yj += (base->yj >= base->win_y ? 0 : 1);
	}
	else if (k == 126)
	{
		base->view.zoom++;
		//base->yj -=	(base->yj <= 0 ? 0 : 1);
	}
	else if (k == 78 && base->interval > -200)
		base->interval -= 1;
	else if (k == 69 && base->interval < 200)
		base->interval += 1;
	ft_putstr("interval = ");
	ft_putnbrendl(base->interval);
}

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *base)
{
			ft_putendlcolor("refresh()", MAGENTA);
	int	i;

	i = 0;
	while (i < (base->win_size - 1))
		base->data[i++] = 0;
	draw_verti(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
}

/*
** Redirect the events 
*/

int		event(int keycode, void *param)
{
			ft_putendlcolor("event()", MAGENTA);
	t_base  *base;

	base = (t_base *)param;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || 
		keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126 ||
		keycode == 69 || keycode == 78)
		move(keycode, base);
	if (keycode == 53)
		exit(1);
	refresh(base);
	return (0);
}