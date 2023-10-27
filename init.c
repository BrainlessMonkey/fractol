/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:25:53 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

static void	data_init(t_fractal *f)
{
	f->max_val = 4;
	f->nb_iter = 42;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
}

static void	events_init(t_fractal *f)
{
	mlx_hook(f->window, KeyPress,
		KeyPressMask, key_handler, f);
	mlx_hook(f->window, ButtonPress,
		ButtonPressMask, mouse_handler, f);
	mlx_hook(f->window, DestroyNotify,
		StructureNotifyMask, close_handler, f);
	mlx_hook(f->window, MotionNotify,
		PointerMotionMask, tracking_handler, f);
}

void	fractal_init(t_fractal *f)
{
	f->connection = mlx_init();
	if (NULL == f->connection)
		print_error("Error: malloc", 2);
	f->window = mlx_new_window(f->connection,
			SIDE, SIDE, f->name);
	if (NULL == f->window)
	{
		mlx_destroy_display(f->connection);
		free(f->connection);
		print_error("Error: malloc", 3);
	}
	f->img.img = mlx_new_image(f->connection,
			SIDE, SIDE);
	if (NULL == f->img.img)
	{
		mlx_destroy_window(f->connection, f->window);
		mlx_destroy_display(f->connection);
		free(f->connection);
		print_error("Error: malloc", 4);
	}
	f->img.pixels = mlx_get_data_addr(f->img.img,
			&f->img.bpp, &f->img.line_len, &f->img.end);
	events_init(f);
	data_init(f);
}
