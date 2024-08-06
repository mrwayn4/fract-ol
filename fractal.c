/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:55:21 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/29 01:50:25 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_dimen(int x, int y)
{
	return (x < 20 || y < 20 || x > 2000 || y > 2000);
}

static void	f_events(t_fractal *f)
{
	mlx_hook(f->mlx_win, 2, 0, key_hook, f);
	mlx_hook(f->mlx_win, 4, 0, mouse, f);
	mlx_hook(f->mlx_win, 17, 0, close_win, f);
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
			|| (ac == 4 && !ft_strcmp(av[1], "julia"))
			|| (ac == 2 && !ft_strcmp(av[1], "tricon")))
		&& !ft_dimen(WIDTH, HEIGHT))
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			if (invalid_input(av[2]) || invalid_input(av[3]))
				(help_msg(), exit(EXIT_FAILURE));
			f.julia_y = atoi_dbl(av[2]);
			f.julia_x = atoi_dbl(av[3]);
		}
		f.name = av[1];
		f_init(&f);
		f_render(&f);
		f_events(&f);
		mlx_loop(f.mlx);
	}
	else
		(help_msg(), exit(EXIT_FAILURE));
}
