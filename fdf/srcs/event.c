/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:07:14 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/13 20:57:56 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Move position of the map
*/

void	ev_move(int k, t_base *base)
{
	if (k == 0)
		base->xi -= (base->xi <= 0 ? 0 : 1);	
	else if (k == 123)
		base->leftright++;
	else if (k == 124)
		base->leftright--;
	else if (k == 125)
		base->updown++;
	else if (k == 126)
		base->updown--;
	else if (k == 43)
	{
		base->alt--;
		base->interval -= 1;
	}
	else if (k == 47)
	{
		base->alt++;
		base->interval += 1;	
	}
}

/*
** Other events like exit & zoom
*/

void	ev_else(int k, t_base *base)
{
	if (k == 53)
		exit(1);
	else if (k == 78 && base->interval > -200)
		base->view.zoom--;
	else if (k == 69 && base->interval < 200)
		base->view.zoom++;
	base->color = (k == 83) ? 0xff0000 : base->color;
	base->color = (k == 84) ? 0x00ff00 : base->color;
	base->color = (k == 85) ? 0x0000ff : base->color;
	base->color = (k == 86) ? 0xaa00ff : base->color;
	base->color = (k == 87) ? 0xffffff : base->color;
	base->color = (k == 88) ? 0xfd9b06 : base->color;
	base->color = (k == 89) ? 0xff3ad9 : base->color;
	base->color = (k == 91) ? 0x2a9c9c : base->color;
	base->color = (k == 92) ? 0xbdf6e9 : base->color;
}

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *base)
{
	int	i;

	i = 0;
	while (i < (base->win_size - 1))
		base->data[i++] = 0;
	draw_verti(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	ui(base);
}

/*
** Redirect the events 
*/

int		event(int keycode, void *param)
{
	t_base  *base;

	base = (t_base *)param;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || 
		keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126
		|| keycode == 43 || keycode == 47)
		ev_move(keycode, base);
	if (keycode == 69 || keycode == 78 || keycode == 53 || 
		keycode == 27 || keycode == 24 || (keycode >= 83 && keycode <= 92))
		ev_else(keycode, base);
	refresh(base);
	return (0);
}