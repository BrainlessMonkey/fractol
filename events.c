/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:25:53 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->connection,
		f->img.img);
	mlx_destroy_window(f->connection,
		f->window);
	mlx_destroy_display(f->connection);
	free(f->connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	if (keysym == XK_Left)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == XK_Right)
		f->shift_x += (0.5 * f->zoom);
	else if (keysym == XK_Up)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == XK_Down)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == XK_plus || keysym == 65451)
		f->nb_iter += 10;
	else if (keysym == XK_minus || keysym == 65453)
		f->nb_iter -= 10;
	render(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	(void)x;
	(void)y;
	if (button == Button5)
		f->zoom *= 1.05;
	else if (button == Button4)
		f->zoom *= 0.95;
	render(f);
	return (0);
}

int	tracking_handler(int x, int y, t_fractal *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->xj = (scaling(x, -2, +2, SIDE) * f->zoom)
			+ f->shift_x;
		f->yj = (scaling(y, +2, -2, SIDE) * f->zoom)
			+ f->shift_y;
		render(f);
	}
	return (0);
}
