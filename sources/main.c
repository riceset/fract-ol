/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/28 00:48:39 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define WIDTH 900
#define HEIGHT 900

struct s_fractal
{
	void *mlx;
	void *win;

	double max_re;
	double min_re;

	double max_im;
	double min_im;
};

typedef struct s_fractal t_fractal;

int main(void)
{
	t_fractal f;

	f.mlx = mlx_init();

	f.min_re = -2.0;
	f.max_re = +1.0;

	f.min_im = -1.5;
	f.max_im = (f.max_re - f.min_re) * HEIGHT / WIDTH + f.min_im;

	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "fract'ol");

	mlx_pixel_put(f.mlx, f.win, 100, 100, 0x000000FF);

	mlx_loop(f.mlx);

	return (0);
}
