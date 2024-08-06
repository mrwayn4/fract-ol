/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:05:17 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/27 01:34:27 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	f_init(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(EXIT_FAILURE);
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (!f->mlx_win)
		exit(EXIT_FAILURE);
	f->im.ip = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->im.ip)
		exit(EXIT_FAILURE);
	f->im.addr = mlx_get_data_addr(f->im.ip, &f->im.bp, &f->im.ll, &f->im.en);
	if (!f->im.addr)
		exit(EXIT_FAILURE);
	f->z.r = 0.0;
	f->z.i = 0.0;
	f->iter = 60;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->max_r = 2.0;
	f->max_i = -2.0;
	f->min_r = -2.0;
	f->min_i = 2.0;
	f->r = 3;
	f->g = 5;
	f->b = 7;
	f->zoom_shift = 1.0;
}
