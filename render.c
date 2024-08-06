/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:28:24 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/27 01:35:20 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale(double u, double n_min, double n_max, double o_max)
{
	double	o_min;

	o_min = 0;
	return ((n_max - n_min) * (u - o_min) / (o_max - o_min) + n_min);
}

void	handle_render(double x, double y, t_fractal *f)
{
	f->z.r = scale(x, f->min_r, f->max_r, WIDTH) + f->shift_x;
	f->z.i = scale(y, f->min_i, f->max_i, HEIGHT) + f->shift_y;
	if (!ft_strcmp(f->name, "mandelbrot"))
		mandelbrot(x, y, f);
	else if (!ft_strcmp(f->name, "julia"))
		julia(x, y, f);
	else if (!ft_strcmp(f->name, "tricon"))
		tricon(x, y, f);
}

void	f_render(t_fractal *f)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_render(x, y, f);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->im.ip, 0, 0);
}
