/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:11:52 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/27 01:35:57 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixel_put(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->ll) + (x * (img->bp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	mandelbrot(double x, double y, t_fractal *f)
{
	t_cmpx	c;
	int		i;
	double	tmp;
	int		color;

	i = -1;
	c.i = f->z.i;
	c.r = f->z.r;
	while (++i < f->iter)
	{
		if ((f->z.r * f->z.r) + (f->z.i * f->z.i) > 4.0)
		{
			color = color_iter(i, f);
			pixel_put(x, y, color, &f->im);
			return ;
		}
		tmp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + c.r;
		f->z.i = 2 * f->z.r * f->z.i + c.i;
		f->z.r = tmp;
	}
	color = 0x000000;
	pixel_put(x, y, color, &f->im);
}

void	julia(double x, double y, t_fractal *f)
{
	t_cmpx	c;
	int		i;
	double	tmp;
	int		color;

	i = -1;
	c.i = f->julia_x;
	c.r = f->julia_y;
	while (++i < f->iter)
	{
		if ((f->z.r * f->z.r) + (f->z.i * f->z.i) > 4.0)
		{
			color = color_iter(i, f);
			pixel_put(x, y, color, &f->im);
			return ;
		}
		tmp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + c.r;
		f->z.i = 2 * f->z.r * f->z.i + c.i;
		f->z.r = tmp;
	}
	color = 0x000000;
	pixel_put(x, y, color, &f->im);
}

void	tricon(double x, double y, t_fractal *f)
{
	t_cmpx	c;
	int		i;
	double	tmp;
	int		color;

	i = -1;
	c.i = f->z.i;
	c.r = f->z.r;
	while (++i < f->iter)
	{
		if ((f->z.r * f->z.r) + (f->z.i * f->z.i) > 4.0)
		{
			color = color_iter(i, f);
			pixel_put(x, y, color, &f->im);
			return ;
		}
		tmp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + c.r;
		f->z.i = -2 * f->z.r * f->z.i + c.i;
		f->z.r = tmp;
	}
	color = 0x000000;
	pixel_put(x, y, color, &f->im);
}
