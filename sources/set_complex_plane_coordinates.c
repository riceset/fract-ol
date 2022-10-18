/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_complex_plane_coordinates.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:42 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mandelbrot_coordinates(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +1.0;
	f->min.im = -1.5;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
}

void	set_julia_coordinates(char **argv, t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +2.0;
	f->min.im = -2.0;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
	f->k.re = ft_atof(argv[2]);
	f->k.im = ft_atof(argv[3]);
}

void	set_complex_plane_coordinates(char **argv, t_fractal *f)
{
	if (f->name == MANDELBROT)
		set_mandelbrot_coordinates(f);
	if (f->name == JULIA)
		set_julia_coordinates(argv, f);
}
