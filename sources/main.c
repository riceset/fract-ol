/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:20:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:37:28 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	m;

	if (check_args(argc, argv) && init_mlx(&m) && init_fractal(argv, &m.f))
	{
		mlx_loop_hook(m.mlx, draw_and_put_image, &m);
		mlx_hook(m.win, KeyPress, KeyPressMask, handle_keypress, &m);
		mlx_hook(m.win, DestroyNotify, NoEventMask, close_window, &m);
		mlx_mouse_hook(m.win, mouse_hook, &m);
		mlx_loop(m.mlx);
		return (finalized_with_success(&m));
	}
	return (ERROR);
}
