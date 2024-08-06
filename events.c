/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:38:01 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/29 01:06:20 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_win(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->im.ip);
	mlx_destroy_window(f->mlx, f->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC)
	{
		close_win(f);
		exit(0);
	}
	else if (keycode == MINUS)
		f->iter -= 10;
	else if (keycode == PLUS)
		f->iter += 10;
	else if (keycode == RIGHT)
		f->shift_x += 0.5 * f->zoom_shift;
	else if (keycode == LEFT)
		f->shift_x += -0.5 * f->zoom_shift;
	else if (keycode == DOWN)
		f->shift_y += 0.5 * f->zoom_shift;
	else if (keycode == UP)
		f->shift_y += -0.5 * f->zoom_shift;
	else if (keycode == SPACE)
		color_shift(f);
	else
		return (0);
	f_render(f);
	return (0);
}

static void	zoom(t_fractal *f, double x, double y)
{
	f->max_r = x + f->zoom * (f->max_r - x);
	f->min_r = x + f->zoom * (f->min_r - x);
	f->max_i = y + f->zoom * (f->max_i - y);
	f->min_i = y + f->zoom * (f->min_i - y);
}

int	mouse(int mousecode, int x, int y, t_fractal *f)
{
	double	re;
	double	im;

	re = scale(x, f->min_r, f->max_r, WIDTH);
	im = scale(y, f->min_i, f->max_i, HEIGHT);
	if (mousecode == ZOOM_IN)
	{
		f->zoom = 1.1;
		f->zoom_shift *= 1.1;
		zoom(f, re, im);
	}
	else if (mousecode == ZOOM_OUT)
	{
		f->zoom = 0.9;
		f->zoom_shift *= 0.9;
		zoom(f, re, im);
	}
	else
		return (0);
	f_render(f);
	return (0);
}
