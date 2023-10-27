/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 03:25:53 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_pixel(int x, int y, t_img *img, int color)
{
	*(unsigned int *)(img->pixels + ((y * img->line_len)
				+ (x * (img->bpp / 8)))) = color;
}

static void	f_type(t_complex *z, t_complex *c, t_fractal *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		c->x = f->xj;
		c->y = f->yj;
		return ;
	}
	c->x = z->x;
	c->y = z->y;
}

static void	treat_pixel(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = (scaling(x, -2, +2, SIDE) * f->zoom) + f->shift_x;
	z.y = (scaling(y, +2, -2, SIDE) * f->zoom) + f->shift_y;
	f_type(&z, &c, f);
	while (++i < f->nb_iter)
	{
		z = calc(z, c);
		if ((z.x * z.x) + (z.y * z.y) > f->max_val)
		{
			color = scaling(i, BLACK, WHITE, f->nb_iter);
			color_pixel(x, y, &f->img, color);
			return ;
		}
	}
	color_pixel(x, y, &f->img, WHITE);
}

void	render(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIDE)
	{
		x = -1;
		while (++x < SIDE)
			treat_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->connection, f->window,
		f->img.img, 0, 0);
}
