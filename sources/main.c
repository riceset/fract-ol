/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:23:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	m;

	if (check_args(argc, argv) && init_fractal(argv, &m.f) && init_mlx(&m))
	{
		mlx_loop_hook(m.mlx, draw_and_put_image, &m);
		mlx_hook(m.win, KeyPress, KeyPressMask, handle_keypress, &m);
		mlx_hook(m.win, DestroyNotify, NoEventMask, close_window_x, &m);
		mlx_mouse_hook(m.win, mouse_hook, &m);
		mlx_loop(m.mlx);
		return (finalized_with_success(&m));
	}
	return (ERROR);
}
