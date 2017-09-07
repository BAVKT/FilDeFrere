/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:08:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/07 16:08:54 by vmercadi         ###   ########.fr       */
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
	base->xj = 150;
	base->yj = 10;
	base->size = 0;
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
			ft_putendlcolor("init_image()", MAGENTA);
	base->img = mlx_new_image(base->mlx, base->win_x, base->win_y);
	base->data = (int*)mlx_get_data_addr(base->img, &disp->bpp, &disp->sizeline, &disp->endian);
}

/*
** Write the pixel in the mage
*/

void	px2img(t_base *base, int x, int y, int color)
{
		//ft_putendlcolor("px2img()", MAGENTA);
	if (x > base->win_x || x < 0 || y > base->win_y || y < 0)
		return ;
	base->data[y * base->win_y + x] = color;
}

/*
** Draw the lines between the 2 points 
*/

void	line(t_base *base)
{
	int	dx;
	int	dy;
	int	cumul;

	base->x = base->xi;
	base->y = base->yi;
	dx = base->xj - base->xi;
	dy = base->yj - base->yi;
	px2img(base, base->x, base->y, 0xffffff);
	cumul = dx / 2;
	//base->x = base->xi + 1;
	while (base->x <= base->xj)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			base->y += 1;
		}
		px2img(base, base->x, base->y, 0xffffff);
		base->x++;
	}
}


void	draw(t_base *base)
{
//			ft_putendlcolor("draw()", MAGENTA);
	int		x;
	int		y;

	y = 1;
	while (y <= base->y)
	{
		x = 1;
		while (x <= base->x)
		{
			line(base);
			x++;
		}
		y++;
	}
	// px2img(base, base->xi, base->yi, 0xffffff);
	// px2img(base, base->xj, base->yj, 0xffffff);
}

/*
** Move the points
*/

void	move(int k, t_base *base)
{
			ft_putendlcolor("move()", MAGENTA);
		ft_putnbrendl(k);
	if (k == 0)
		base->xi -= (base->xi <= 0 ? 0 : 5);
	else if (k == 1)
		base->yi +=	(base->yi >= base->win_y ? 0 : 5);
	else if (k == 2)
		base->xi +=	(base->xi >= base->win_x ? 0 : 5);
	else if (k == 13)
		base->yi -= (base->yi <= 0 ? 0 : 5);
	else if (k == 123)
		base->xj -=	(base->xj <= 0 ? 0 : 5);
	else if (k == 124)
		base->xj += (base->xj >= base->win_x ? 0 : 5);
	else if (k == 125)
		base->yj += (base->yj >= base->win_y ? 0 : 5);
	else if (k == 126)
		base->yj -=	(base->yj <= 0 ? 0 : 1);
		ft_putendl("end move");
}

void	refresh(t_base *base)
{
			ft_putendlcolor("refresh()", MAGENTA);
	int	i;

	i = 0;
		ft_putnbrendl(base->win_size);
	while (i < (base->win_size - 1))
		base->data[i++] = 0;
	draw(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
}

/*
** Redirect event 
*/

int		event(int keycode, void *param)
{
			ft_putendlcolor("event()", MAGENTA);
	t_base  *base;

	base = (t_base *)param;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13 || 
		keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move(keycode, base);
	if (keycode == 53)
		exit(1);
	refresh(base);
	return (0);
}

void	fdf(t_base *base)
{
			ft_putendlcolor("fdf()", MAGENTA);
	draw(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	mlx_hook(base->win, 2, 0, event, base);
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
