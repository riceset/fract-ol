/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:23:54 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:35:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_1(t_mlx *m, int i, int x, int y)
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
	pixel_put(m, x, y, color);
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
