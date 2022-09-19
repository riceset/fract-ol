/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:02:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/09/19 11:28:03 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 1200
#define HEIGHT 3000

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// linha / coluna
// [y][x]
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int line_length;

	line_length = data->line_length / 4;
	data->addr[y * line_length + x] = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	//inicia a struct (constructor)
	mlx = mlx_init();
	
	//Inicializa a janela tipo do chrome terminal etc
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");

	//Inicializa oq eu vou por dentro da janela
	//espaco reservado na memoria pra preencher a janela
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);

	//raw data da imagem. enderecos e informacoes pra percorrer na imagem
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			my_mlx_pixel_put(&img, x, y, 0x000000FF);

	//Carrega tudo na memoria e coloca tudo de uma vez na tela com uma
	//syscall
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	
	return (0);
}
