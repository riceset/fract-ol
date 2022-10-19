/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:24:33 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:26:35 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_mlx *m)
{
	t_complex	pixel;
	double		y;
	double		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel.re = m->f.min.re + x * (m->f.max.re - m->f.min.re) / WIDTH;
			pixel.im = m->f.min.im + y * (m->f.max.im - m->f.min.im) / HEIGHT;
			if (m->f.name == MANDELBROT)
				set_color(m, mandelbrot(pixel), x, y);
			if (m->f.name == JULIA)
				set_color(m, julia(m, pixel), x, y);
			x++;
		}
		y++;
	}
}
