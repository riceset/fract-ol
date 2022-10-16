/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/16 05:23:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

bool print_error(char *message)
{
	ft_printf(RED "Error" CRESET ": %s\n", message);
	return (false);
}

void set_mandelbrot_coordinates(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +1.0;
	f->min.im = -1.5;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
}

void set_julia_coordinates(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +2.0;
	f->min.im = -2.0;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;
	f->k.re = -0.766667;
	f->k.im = -0.090000;
}

void set_complex_plane_coordinates(t_fractal *f)
{
	if (f->name == MANDELBROT)
		set_mandelbrot_coordinates(f);
	if (f->name == JULIA)
		set_julia_coordinates(f);
}

bool init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (print_error("Failed to initialize mlx."));

	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!m->win)
	{
		free(m->win);
		return (print_error("Failed to create a window."));
	}

	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	if (!m->img)
	{
		free(m->img);
		return (print_error("Failed to create an image."));
	}

	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length, &m->endian);

	return (true);
}

bool is_mandelbrot(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0
		|| ft_strcmp(name, "mandelbrot") == 0)
		return (true);
	return (false);
}

bool is_julia(char *name)
{
	if (ft_strcmp(name, "Julia") == 0
		|| ft_strcmp(name, "julia") == 0)
		return (true);
	return (false);
}

void determine_fractal(char *name, t_fractal *f)
{
	if (is_mandelbrot(name))
		f->name = MANDELBROT;
	else if (is_julia(name))
		f->name = JULIA;
}

bool init_fractal(char *name, t_fractal *f)
{
	determine_fractal(name, f);
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

			if (m->f.name == MANDELBROT)
				mandelbrot(&m->f, m, x, y, pixel);
			if (m->f.name == JULIA)
				julia(&m->f, m, x, y, pixel);
		}
}

int draw_and_put_image(t_mlx *m)
{
	if (!m->win)
		return (1);
	mlx_clear_window(m->mlx, m->win);
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

//後で訊いておく。
int	exit_hook(t_mlx *m)
{
	mlx_destroy_window(m->mlx, m->win);
	m->win = NULL;

	return (0);
}

bool check_args(int argc, char **argv)
{
	if (argc == 1)
		return (print_error("Too few arguments."));

	else if (argc > 4)
		return (print_error("Too many arguments."));

	else if (!(is_mandelbrot(argv[1]) || is_julia(argv[1])))
		return (print_error("Invalid set.\n" GRN "Available sets" CRESET ": [" \
				YEL "Mandelbrot" CRESET ", " MAG "Julia" CRESET "]"));

	else if (is_julia(argv[1]) && (argv[2] == NULL || argv[3] == NULL))
		return (print_error("Invalid constant (K) value.\n" \
				GRN "Input for K values" CRESET ": [" YEL "K's REAL PART" \
				CRESET ", " MAG "K's IMAGINARY PART" CRESET "]"));

	return (true);
}

int main(int argc, char **argv)
{
	t_mlx m;

	if (check_args(argc, argv) && init_mlx(&m) && init_fractal(argv[1], &m.f))
	{
		// ft_printf("%s\n", m.f.name ? "JULIA" : "MANDELBROT");
		mlx_loop_hook(m.mlx, draw_and_put_image, &m);

		mlx_hook(m.win, KeyPress, KeyPressMask, handle_keypress, &m);

		//後で訊いておく。
		mlx_hook(m.win, 17, 0, exit_hook, &m);

		mlx_loop(m.mlx);

		return (finalized_with_success(&m));
	}

	return (ERROR);
}
