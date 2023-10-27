/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:25:53 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atod(char *s)
{
	long	itg;
	double	frac;
	double	sub;
	int		sign;

	itg = 0;
	frac = 0;
	sign = +1;
	sub = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		itg = (itg * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		sub /= 10;
		frac = frac + (*s++ - 48) * sub;
	}
	return ((itg + frac) * sign);
}

void	print_error(char *error, int error_int)
{
	perror(error);
	exit(error_int);
}

double	scaling( double num, double min, double max, double old_max)
{
	return ((max - min) * (num - 0) / (old_max - 0) + min);
}

t_complex	calc(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.y = 2 * z.x * z.y + c.y;
	sum.x = (z.x * z.x) - (z.y * z.y) + c.x;
	return (sum);
}
