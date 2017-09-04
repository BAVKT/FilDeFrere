/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:08:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/04 20:15:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Init the base
*/

void	init(t_base *base)
{
			ft_putendlcolor("init()", MAGENTA);
	base->interval = 25;
	base->x = 25;
	base->y = 25;
	base->xi = 5;
	base->yi = 7;
	base->xj = 10;
	base->yj = 7;
	base->win_x = base->x * base->interval + base->interval;
	base->win_y = base->y * base->interval + base->interval;
	base->win_size = base->win_x * base->win_y;
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, base->win_x, base->win_y, "Phil 2 frer");
	base->img = (int *)malloc(sizeof(int) * base->win_size);
}

/*
** Init the image values
*/

void	init_image(t_base *base, t_disp *disp)
{
			ft_putendlcolor("image()", MAGENTA);
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = (int*)mlx_get_data_addr(base->img, &disp->bpp, &disp->sizeline, &disp->endian);
}

void	px2img(t_base *base, int x, int y, int color)
{
	if (x > base->win_x || x < 0 || y > base->win_y || y < 0)
		return ;
	*&base->data[(base->yi * base->sizeline * base->interval) + base->x * base->interval] = color;
	*&base->data[(base->yj * base->sizeline * base->interval) + base->xj * base->interval] = color;
}

void	draw(t_base *base)
{
	px2img(base, base->xi, base->yi, 0xffffff);
	px2img(base, base->xj, base->yj, 0xffffff);
}

int		fdf_expose(t_base *base)
{
	ft_bzero(base->data, base->size);
	draw(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	return (0);
}


/*
** Move the points
*/

void	move(int k, t_base *base)
{
	if (k == 0)
		base->xi -= (base->xi <= 0 ? 0 : 1);
	if (k == 1)
		base->yi -= (base->yi <= 0 ? 0 : 1);
	if (k == 2)
		base->xi +=	(base->xi >= base->x ? 0 : 1);
	if (k == 13)
		base->yi +=	(base->yi >= base->y ? 0 : 1);
	if (k == 123)
		base->xj -=	(base->xj <= 0 ? 0 : 1);
	if (k == 124)
		base->yj -=	(base->yj <= 0 ? 0 : 1);
	if (k == 125)
		base->xj += (base->xj >= base->x ? 0 : 1);
	if (k == 126)
		base->yj += (base->yj >= base->y ? 0 : 1);
}

/*
** Redirect event 
*/

int		event(int keycode, t_base *base)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || 
		keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move(keycode, base);
	return (0);
}

void	fdf(t_base *base)
{
			ft_putendlcolor("mlx_loop()", MAGENTA);

	mlx_hook(base->win, 2, 0, event, base);
	mlx_expose_hook(base->win, fdf_expose, base);
	draw(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	mlx_loop(base->mlx);
}

int	main()
{
	t_base base;
	t_disp disp;

	init(&base);
	disp = init_display(&base);
	init_image(&base, &disp);
	fdf(&base);
	return (0);
}
