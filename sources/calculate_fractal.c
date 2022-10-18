/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:23:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:34:50 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_mlx *m, int x, int y, t_complex z)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < 100)
	{
		if (square(z.re) + square(z.im) > 4.0)
			break ;
		tmp = 2 * z.re * z.im + m->f.k.im;
		z.re = square(z.re) - square(z.im) + m->f.k.re;
		z.im = tmp;
		i++;
	}
	return (i);
}

int	mandelbrot(t_mlx *m, int x, int y, t_complex c)
{
	int			i;
	t_complex	z;
	double		tmp;

	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (i < 100)
	{
		if (square(z.re) + square(z.im) > 4.0)
			break ;
		tmp = 2 * z.re * z.im + c.im;
		z.re = square(z.re) - square(z.im) + c.re;
		z.im = tmp;
		i++;
	}
	return (i);
}
