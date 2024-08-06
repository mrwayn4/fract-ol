/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:48 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/22 17:33:03 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	color_iter(int iter, t_fractal *f)
{
	int	r;
	int	g;
	int	b;

	r = (iter * f->r) % 255;
	g = (iter * f->g) % 255;
	b = (iter * f->b) % 255;
	return (r << 16 | g << 8 | b);
}

void	color_shift(t_fractal *f)
{
	f->r += 2;
	f->r = f->r % 13;
	f->g += 2;
	f->g = f->g % 13;
	f->b += 2;
	f->b = f->b % 13;
}
