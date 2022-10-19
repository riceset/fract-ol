/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:25:09 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:27:02 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window_esc(int keycode, t_mlx *m)
{
	(void)keycode;
	mlx_destroy_window(m->mlx, m->win);
	m->win = NULL;
	return (0);
}

int	close_window_x(t_mlx *m)
{
	mlx_destroy_window(m->mlx, m->win);
	m->win = NULL;
	return (0);
}
