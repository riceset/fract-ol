/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/16 02:43:00 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	if (!m->img)
	{
		free(m->img);
		return (false);
	}

	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length, &m->endian);

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
		pixel_put(m, x, y, 0x00000000);
	else
		pixel_put(m, x, y, 0x00FFFFFF);
}


void mandelbrot(t_fractal *f, t_mlx *m, int x, int y, t_complex c)
{
	t_complex z;
	double tmp;
	bool is_in_set;

	z.re = 0.0;
	z.im = 0.0;

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
		pixel_put(m, x, y, 0x00000000);
	else
		pixel_put(m, x, y, 0x00FFFFFF);
}

void draw_fractal(t_mlx *m)
{
	t_complex pixel;

	for (double y = 0; y < HEIGHT; y++)
		for (double x = 0; x < WIDTH; x++)
		{
			pixel.re = m->f.min.re + x * (m->f.max.re - m->f.min.re) / WIDTH;
			pixel.im = m->f.min.im + y * (m->f.max.im - m->f.min.im) / HEIGHT;

			julia(&m->f, m, x, y, pixel);
		}
}

int draw_and_put_image(t_mlx *m)
{
	draw_fractal(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);

	return (0);
}

void close_window(int keycode, t_mlx *m)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(m->mlx, m->win);
		m->win = NULL;
	}
}
void zoom_in_on_key(int keycode, t_mlx *m)
{
	if (keycode == XK_z)
	{
		m->f.min.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
}

void zoom_out_on_key(int keycode, t_mlx *m)
{
	if (keycode == XK_x)
	{
		m->f.min.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
}

void zoom_on_key(int keycode, t_mlx *m)
{
	zoom_in_on_key(keycode, m);
	zoom_out_on_key(keycode, m);
}

void camera_up(int keycode, t_mlx *m)
{
	if (keycode == XK_Up)
	{
		m->f.min.im -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im -= (m->f.max.re - m->f.min.re) * 0.115;
	}
}

void camera_down(int keycode, t_mlx *m)
{
	if (keycode == XK_Down)
	{
		m->f.min.im += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im += (m->f.max.re - m->f.min.re) * 0.115;
	}
}

void camera_left(int keycode, t_mlx *m)
{
	if (keycode == XK_Left)
	{
		m->f.min.re -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.re -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
}

void camera_right(int keycode, t_mlx *m)
{
	if (keycode == XK_Right)
	{
		m->f.min.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
}

void camera_movement(int keycode, t_mlx *m)
{
	camera_up(keycode, m);
	camera_down(keycode, m);
	camera_left(keycode, m);
	camera_right(keycode, m);
}

int handle_keypress(int keycode, t_mlx *m)
{
	close_window(keycode, m);
	zoom_on_key(keycode, m);
	camera_movement(keycode, m);

	return (0);
}

int finalized_with_success(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_display(m->mlx);
	mlx_loop_end(m->mlx);
	free(m->mlx);

	return (SUCCESS);
}

int main(void)
{
	t_mlx m;

	if (initialized_mlx(&m) && initialized_fractal(&m.f))
	{
		mlx_loop_hook(m.mlx, draw_and_put_image, &m);
		mlx_hook(m.win, KeyPress, KeyPressMask, handle_keypress, &m);
		mlx_loop(m.mlx);
		return (finalized_with_success(&m));
	}

	return (ERROR);
}
