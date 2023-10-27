/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:05:03 by adedieu           #+#    #+#             */
/*   Updated: 2023/10/27 21:02:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft/libft.h"

# define ERROR "Usage: fractol mandelbrot or fractol julia <val1> <val2>\n"
# define SIDE	500
# define BLACK	0x000000 
# define WHITE	0xFFFFFF

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		end;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*connection;
	void	*window;
	t_img	img;
	double	max_val;
	int		nb_iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	xj;
	double	yj;
}				t_fractal;

void		putstr_fd(char *s, int fd);
double		atod(char *s);
void		fractal_init(t_fractal *f);
void		render(t_fractal *f);
double		scaling(double num, double min, double max, double old_max);
int			key_handler(int keysym, t_fractal *f);
int			close_handler(t_fractal *f);
int			mouse_handler(int button, int x, int y, t_fractal *f);
int			tracking_handler(int x, int y, t_fractal *f);
void		print_error(char *error, int error_int);
t_complex	calc(t_complex z, t_complex c);

#endif
