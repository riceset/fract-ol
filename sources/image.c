/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:02:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/22 14:45:45 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define MLX_ERROR 1

#define WIDTH 800
#define HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

int	main(void)
{
	t_data  d;
	t_img 	mlx_img;

	d.mlx = mlx_init();
	if (!d.mlx)
		return (MLX_ERROR);

	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "fractol");
	if (!d.win)
	{
		free(d.win);
		return (MLX_ERROR);
	}

	mlx_img.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);

	mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bpp, &mlx_img.line_len, &mlx_img.endian);

	mlx_loop(d.mlx);

	mlx_destroy_window(d.mlx, d.win);
	
	free(d.mlx);
}
