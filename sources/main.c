/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/16 08:37:47 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO: atofのエラー処理

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || ('\x09' <= str[i] && str[i] <= '\x0D'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}

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

void set_julia_coordinates(char **argv, t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = +2.0;
	f->min.im = -2.0;
	f->max.im = (f->max.re - f->min.re) * HEIGHT / WIDTH + f->min.im;

	f->k.re = ft_atof(argv[2]);
	f->k.im = ft_atof(argv[3]);
	// f->k.re = -0.766667;
	// f->k.im = -0.090000;
}

void set_complex_plane_coordinates(char **argv, t_fractal *f)
{
	if (f->name == MANDELBROT)
		set_mandelbrot_coordinates(f);
	if (f->name == JULIA)
		set_julia_coordinates(argv, f);
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

bool init_fractal(char **argv, t_fractal *f)
{
	determine_fractal(argv[1], f);
	set_complex_plane_coordinates(argv, f);

	return (true);
}

double square(double x)
{
	return (x * x);
}

int julia(t_fractal *f, t_mlx *m, int x, int y, t_complex z)
{
	int i;
	double tmp;

	i = 0;
	while (i < 100)
	{
		if (square(z.re) + square(z.im) > 4.0)
			break ;
		tmp = 2 * z.re * z.im + f->k.im;
		z.re = square(z.re) - square(z.im) + f->k.re;
		z.im = tmp;
		i++;
	}
	return (i);
}


int mandelbrot(t_fractal *f, t_mlx *m, int x, int y, t_complex c)
{
	int i;
	t_complex z;
	double tmp;

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

void	color_1(t_mlx *f, int i, int x, int y)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (i % 8 == 7)
		color = 0x00C9BF63;
	else if (i % 8 == 6)
		color = 0x008F00FF;
	else if (i % 8 == 5)
		color = 0x4B0082;
	else if (i % 8 == 4)
		color = 0x000000FF;
	else if (i % 8 == 3)
		color = 0x0000FF00;
	else if (i % 8 == 2)
		color = 0x00FFFF00;
	else if (i % 8 == 1)
		color = 0x00FF7F00;
	else if (i % 8 == 0)
		color = 0x00FF0000;
	pixel_put(f, x, y, color);
}

void	color_2(t_mlx *m, int i, int x, int y)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (i % 8 == 7)
		color = 0x00FF0000;
	else if (i % 8 == 6)
		color = 0x00FF0381;
	else if (i % 8 == 5)
		color = 0x00FFCC00;
	else if (i % 8 == 4)
		color = 0x00D1F40B;
	else if (i % 8 == 3)
		color = 0x00FB9AC0;
	else if (i % 8 == 2)
		color = 0x00EAF49D;
	else if (i % 8 == 1)
		color = 0x0053E3EA;
	else if (i % 8 == 0)
		color = 0x006BB6F7;
	pixel_put(m, x, y, color);
}

void	color_3(t_mlx *m, int i, int x, int y)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (i % 8 == 7)
		color = 0x00fafa6e;
	else if (i % 8 == 6)
		color = 0x00b5e877;
	else if (i % 8 == 5)
		color = 0x0077d183;
	else if (i % 8 == 4)
		color = 0x003fb78d;
	else if (i % 8 == 3)
		color = 0x00009c8f;
	else if (i % 8 == 2)
		color = 0x00007f86;
	else if (i % 8 == 1)
		color = 0x001c6373;
	else if (i % 8 == 0)
		color = 0x002a4858;
	pixel_put(m, x, y, color);
}

void	color_4(t_mlx *m, int i, int x, int y)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (i % 8 == 1)
		color = 0x00f51b4e;
	else if (i % 8 == 2)
		color = 0x00ff3363;
	else if (i % 8 == 3)
		color = 0x00f25076;
	else if (i % 8 == 4)
		color = 0x00f26f8e;
	else if (i % 8 == 5)
		color = 0x00f28aa2;
	else if (i % 8 == 6)
		color = 0x00f5a6b8;
	else if (i % 8 == 7)
		color = 0x00f7bac8;
	else if (i % 8 == 0)
		color = 0x00d40233;
	pixel_put(m, x, y, color);
}

void	color_5(t_mlx *m, int i, int x, int y)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (i % 8 == 7)
		color = 0x00cbbbfc;
	else if (i % 8 == 6)
		color = 0x00bca7fc;
	else if (i % 8 == 5)
		color = 0x00af95fc;
	else if (i % 8 == 4)
		color = 0x009e7ffa;
	else if (i % 8 == 3)
		color = 0x008c66fa;
	else if (i % 8 == 2)
		color = 0x00774af7;
	else if (i % 8 == 1)
		color = 0x00622dfa;
	else if (i % 8 == 0)
		color = 0x004c0ffc;
	pixel_put(m, x, y, color);
}

void	set_color(t_mlx *m, int i, int x, int y)
{
	if (m->color % 5 == 0)
		color_1(m, i, x, y);
	else if (m->color % 5 == 1)
		color_2(m, i, x, y);
	else if (m->color % 5 == 2)
		color_3(m, i, x, y);
	else if (m->color % 5 == 3)
		color_4(m, i, x, y);
	else if (m->color % 5 == 4)
		color_5(m, i, x, y);
}

void draw_fractal(t_mlx *m)
{
	t_complex pixel;
	double y;
	double x;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel.re = m->f.min.re + x * (m->f.max.re - m->f.min.re) / WIDTH;
			pixel.im = m->f.min.im + y * (m->f.max.im - m->f.min.im) / HEIGHT;

			if (m->f.name == MANDELBROT)
				set_color(m, mandelbrot(&m->f, m, x, y, pixel), x, y);
			if (m->f.name == JULIA)
				set_color(m, julia(&m->f, m, x, y, pixel), x, y);
			x++;
		}
		y++;
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

int close_window(int keycode, t_mlx *m)
{
	mlx_destroy_window(m->mlx, m->win);
	m->win = NULL;

	return (0);
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
	if (keycode == XK_Up || keycode == XK_k)
	{
		m->f.min.im -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.im -= (m->f.max.im - m->f.min.im) * 0.115;
	}
}

void camera_down(int keycode, t_mlx *m)
{
	if (keycode == XK_Down || keycode == XK_j)
	{
		m->f.min.im += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.im += (m->f.max.im - m->f.min.im) * 0.115;
	}
}

void camera_left(int keycode, t_mlx *m)
{
	if (keycode == XK_Left || keycode == XK_h)
	{
		m->f.min.re -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.re -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
}

void camera_right(int keycode, t_mlx *m)
{
	if (keycode == XK_Right || keycode == XK_l)
	{
		m->f.min.re += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.re += (m->f.max.re - m->f.min.re) * 0.115;
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

void change_color(int keycode, t_mlx *m)
{
	if (keycode == XK_c)
		m->color++;
}

int handle_keypress(int keycode, t_mlx *m)
{
	if (keycode == XK_Escape)
		close_window(keycode, m);
	zoom_on_key(keycode, m);
	camera_movement(keycode, m);
	change_color(keycode, m);

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

bool check_args(int argc, char **argv)
{
	if (argc == 1)
		return (print_error("Too few arguments."));

	else if (argc > 4 || (is_mandelbrot(argv[1]) && argc > 2))
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

int mouse_hook(int keycode, int x, int y, t_mlx *m)
{
	if (keycode == SCROLL_ZOOM_IN)
	{
		m->f.min.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}
	else if (keycode == SCROLL_ZOOM_OUT)
	{
		m->f.min.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT / WIDTH;
	}

	return (0);
}

int main(int argc, char **argv)
{
	t_mlx m;

	if (check_args(argc, argv) && init_mlx(&m) && init_fractal(argv, &m.f))
	{
		mlx_loop_hook(m.mlx, draw_and_put_image, &m);

		mlx_hook(m.win, KeyPress, KeyPressMask, handle_keypress, &m);
		mlx_hook(m.win, DestroyNotify, NoEventMask, close_window, &m);
		mlx_mouse_hook(m.win, mouse_hook, &m);

		mlx_loop(m.mlx);

		return (finalized_with_success(&m));
	}

	return (ERROR);
}
