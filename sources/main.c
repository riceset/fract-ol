/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/28 08:58:10 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

enum e_mlx_status
{
	MLX_SUCCESS,
	MLX_ERROR
};

typedef enum e_mlx_status	t_mlx_status;

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
		draw_square(f);
		mlx_loop(f.mlx);

		return (0);
	}

	return (1);
}
