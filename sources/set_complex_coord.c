/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_complex_coordinates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:42 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:35:07 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mandelbrot_coord(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +1.0;
	f->min.im = -1.5;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
}

void	set_julia_coord(char **argv, t_fractal *f, bool *is_valid)
{
	f->min.re = -2.0;
	f->max.re = +2.0;
	f->min.im = -2.0;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
	f->k.re = ft_atof(argv[2], is_valid);
	f->k.im = ft_atof(argv[3], is_valid);
}

void	set_complex_coord(char **argv, t_fractal *f, bool *is_valid)
{
	if (f->name == MANDELBROT)
		set_mandelbrot_coord(f);
	if (f->name == JULIA)
		set_julia_coord(argv, f, is_valid);
}
