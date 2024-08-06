/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:55:27 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/29 01:49:15 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*ip;
	char	*addr;
	int		bp;
	int		en;
	int		ll;
}				t_img;

typedef struct s_cmpx
{
	double	r;
	double	i;
}				t_cmpx;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	char	*name;
	t_img	im;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	t_cmpx	z;
	int		r;
	int		g;
	int		b;
	double	zoom_shift;
	double	zoom;
	double	max_r;
	double	max_i;
	double	min_r;
	double	min_i;
}				t_fractal;

enum
{
	ESC = 53,
	MINUS = 78,
	PLUS = 69,
	UP = 125,
	DOWN = 126,
	RIGHT = 124,
	LEFT = 123,
	ZOOM_IN = 4,
	ZOOM_OUT = 5,
	SPACE = 49,
};

int		ft_strcmp(const char *s1, const char *s2);
void	f_init(t_fractal *f);
void	f_render(t_fractal *f);
void	handle_render(double x, double y, t_fractal *f);
int		color_iter(int iter, t_fractal *f);
void	pixel_put(int x, int y, int color, t_img *img);
int		close_win(t_fractal *f);
int		key_hook(int keycode, t_fractal *f);
int		mouse(int mousecode, int x, int y, t_fractal *f);
void	help_msg(void);
void	mandelbrot(double x, double y, t_fractal *f);
void	julia(double x, double y, t_fractal *f);
int		invalid_input(char *input);
void	color_shift(t_fractal *f);
double	atoi_dbl(char *s);
void	tricon(double x, double y, t_fractal *f);
double	scale(double u, double n_min, double n_max, double o_max);
#endif