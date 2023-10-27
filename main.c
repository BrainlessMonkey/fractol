/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:25:53 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	f;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		f.name = av[1];
		if (!ft_strncmp(f.name, "julia", 5))
		{
			f.xj = atod(av[2]);
			f.yj = atod(av[3]);
		}
		fractal_init(&f);
		render(&f);
		mlx_loop(f.connection);
	}
	else
		ft_putstr_fd(ERROR, STDERR_FILENO);
}
