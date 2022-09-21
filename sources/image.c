/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:02:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/21 16:19:43 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define WIDTH 800
#define HEIGHT 800

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
	void	*mlx;
	void 	*mlx_win;
	t_img 	mlx_img;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fractol");

	mlx_img.img = mlx_new_image(mlx, WIDTH, HEIGHT);

	mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bpp, &mlx_img.line_len, &mlx_img.endian);

	mlx_loop(mlx);

	return (0);
}
