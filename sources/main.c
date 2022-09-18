/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:39:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/09/18 12:19:29 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	errors(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Invalid syntax!\n", 1);
		exit(1);
	}
	else
	{
		if (ft_strncmp(argv[1], "Julia", sizeof(argv[1])) != 0
			&& ft_strncmp(argv[1], "Mandelbrot", sizeof(argv[1])) != 0)
		{
			ft_putstr_fd("You should use Julia or Mandelbrot set!\n", 1);
			exit(1);
		}
		else
		{
			ft_putstr_fd("Good job!\n", 1);
			exit(0);
		}
	}
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	errors(argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 700, "Fractol");
	img.img = mlx_new_image(mlx, 1000, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 120, 120, 0x00FF0000);
	mlx_loop(mlx);
}
