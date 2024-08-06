/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:39:31 by ibouram           #+#    #+#             */
/*   Updated: 2024/03/30 01:29:01 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static double	int_part(char **s)
{
	long	int_res;

	int_res = 0;
	while (**s && **s != '.')
	{
		int_res = (int_res * 10) + (**s - 48);
		(*s)++;
	}
	return (int_res);
}

static double	float_part(char *s)
{
	double	frac;
	double	frac_res;

	frac = 1;
	frac_res = 0;
	if (*s == '.')
		s++;
	while (*s)
	{
		frac /= 10;
		frac_res += (*s - 48) * frac;
		s++;
	}
	return (frac_res);
}

int	invalid_input(char *input)
{
	int	i;
	int	p;
	int	len;

	len = ft_strlen(input);
	i = 0;
	p = 0;
	if (len == 0 || (len == 1 && input[0] == '.'))
		return (1);
	if (input[i] == '+' || input[i] == '-')
	{
		if (len == 1)
			return (1);
		i++;
	}
	while (input[i])
	{
		if (input[i] != '.' && (input[i] < '0' || input[i] > '9'))
			return (1);
		p += (input[i] == '.') * 1;
		i++;
	}
	if (p > 1)
		return (1);
	return (0);
}

double	atoi_dbl(char *s)
{
	long	int_res;
	double	frac_res;
	double	frac;
	int		sign;

	sign = 1;
	frac = 1;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	int_res = int_part(&s);
	frac_res = float_part(s);
	return ((int_res + frac_res) * sign);
}
