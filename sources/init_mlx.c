/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:05 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (print_error("Failed to initialize mlx."));
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!m->win)
	{
		free(m->win);
		return (print_error("Failed to create a window."));
	}
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	if (!m->img)
	{
		free(m->img);
		return (print_error("Failed to create an image."));
	}
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length,
			&m->endian);
	return (true);
}
