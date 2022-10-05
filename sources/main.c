/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/05 15:53:19 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void set_complex_plane_coordinates(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +1.0;
	f->k.re = -0.766667;

	f->min.im = -1.5;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
	f->k.im = -0.090000;
}

bool initialized_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (false);

	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!m->win)
	{
		free(m->win);
		return (false);
	}

	return (true);
}

bool initialized_fractal(t_fractal *f)
{
	set_complex_plane_coordinates(f);

	return (true);
}

double square(double x)
{
	return (x * x);
}

void julia(t_fractal *f, t_mlx *m, int x, int y, t_complex z)
{
	double tmp;
	bool is_in_set;

	is_in_set = true;

	for (int i = 0; i < 100; i++)
	{
		if (square(z.re) + square(z.im) > 4.0)
		{
			is_in_set = false;
			break ;
		}

		tmp = 2 * z.re * z.im + f->k.im;
		z.re = square(z.re) - square(z.im) + f->k.re;
		z.im = tmp;
	}

	if (is_in_set)
		mlx_pixel_put(m->mlx, m->win, x, y, 0x00000000);
	else
		mlx_pixel_put(m->mlx, m->win, x, y, 0x00FFFFFF);
}


void mandelbrot(t_fractal *f, t_mlx *m, int x, int y, t_complex c)
{
	t_complex z;
	double tmp;
	bool is_in_set;

	is_in_set = true;

	for (int i = 0; i < 100; i++)
	{
		if (square(z.re) + square(z.im) > 4.0)
		{
			is_in_set = false;
			break ;
		}

		tmp = 2 * z.re * z.im + c.im;
		z.re = square(z.re) - square(z.im) + c.re;
		z.im = tmp;
	}

	if (is_in_set)
		mlx_pixel_put(m->mlx, m->win, x, y, 0x00000000);
	else
		mlx_pixel_put(m->mlx, m->win, x, y, 0x00FFFFFF);
}

void draw_fractal(t_fractal *f, t_mlx *m)
{
	t_complex pixel;

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
		{
			pixel.re = f->min.re + (double)x * (f->max.re - f->min.re) / WIDTH;
			pixel.im = f->min.im + (double)y * (f->max.im - f->min.im) / HEIGHT;

			julia(f, m, x, y, pixel);
		}
}

int main(void)
{
	t_fractal f;
	t_mlx m;

	if (initialized_mlx(&m) && initialized_fractal(&f))
	{
		draw_fractal(&f, &m);
		mlx_loop(m.mlx);
		return (0);
	}

	return (1);
}
