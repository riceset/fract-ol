/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/30 23:51:37 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float to_radians(float theta)
{
	return (theta * PI / 180);
}

void draw_circle(t_fractal f)
{
	int color;
	int radius;
	double x;
	double y;
	double x1;
	double y1;

	x = WIDTH / 2;
	y = HEIGHT / 2;

	radius = 300;
	color = 0x0000FF00;

	for (float theta = 0; theta < 360; theta += 0.01)
	{
		x1 = radius * cos(to_radians(theta));
		y1 = radius * sin(to_radians(theta));

		if (theta >= 180)
			color = 0x00FF0000;

		mlx_pixel_put(f.mlx, f.win, x + x1, y + y1, color);
	}
}

void draw_square(t_fractal f)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x > WIDTH / 2 - 50 && x < WIDTH / 2 + 50)
					&& (y > HEIGHT / 2 - 50 && y < HEIGHT / 2 + 50))
				mlx_pixel_put(f.mlx, f.win, x, y, 0x00FFFF00);
			else
				mlx_pixel_put(f.mlx, f.win, x, y, 0x0000FF00);
		}
	}
}

void draw_triangle(t_fractal f)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x > WIDTH / 2 - 50 && x < WIDTH / 2 + 50)
					&& (y > HEIGHT / 2 - 50 && y < HEIGHT / 2 + 50))
			{
				if (x + y >= 900)
					mlx_pixel_put(f.mlx, f.win, x, y, 0x00FFFF00);
				else
					mlx_pixel_put(f.mlx, f.win, x, y, 0x0000FF00);
			}
			else
				mlx_pixel_put(f.mlx, f.win, x, y, 0x0000FF00);
		}
	}
}

void set_complex_plane_coordinates(t_fractal f)
{
	f.min_re = -2.0;
	f.max_re = +1.0;

	f.min_im = -1.5;
	f.max_im = (f.max_re - f.min_re) * HEIGHT / WIDTH + f.min_im;
}

bool could_initialize_fractal(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (false);

	set_complex_plane_coordinates(*f);

	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!f->win)
	{
		free(f->win);
		return (false);
	}

	return (true);
}

int main(void)
{
	t_fractal f;

	if (could_initialize_fractal(&f))
	{
		draw_circle(f);
		mlx_loop(f.mlx);

		return (SUCCESS);
	}

	return (ERROR);
}
