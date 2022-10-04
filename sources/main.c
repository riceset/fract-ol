/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/04 13:48:29 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void set_complex_plane_coordinates(t_fractal f)
{
	f.min_re = -2.0;
	f.max_re = +1.0;

	f.min_im = -1.5;
	f.max_im = (f.max_re - f.min_re) * HEIGHT / WIDTH + f.min_im;
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
	set_complex_plane_coordinates(*f);

	return (true);
}

double square(double x)
{
	return (x * x);
}

int main(void)
{
	t_fractal f;
	t_mlx m;

	if (initialized_mlx(&m) && initialized_fractal(&f))
	{
		mlx_loop(m.mlx);
		return (0);
	}

	return (1);
}
