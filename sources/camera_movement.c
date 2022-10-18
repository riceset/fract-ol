/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:25:59 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:44:01 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	camera_up(int keycode, t_mlx *m)
{
	if (keycode == XK_Up || keycode == XK_k)
	{
		m->f.min.im -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im -= (m->f.max.re - m->f.min.re) * 0.115;
	}
}

void	camera_down(int keycode, t_mlx *m)
{
	if (keycode == XK_Down || keycode == XK_j)
	{
		m->f.min.im += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im += (m->f.max.re - m->f.min.re) * 0.115;
	}
}

void	camera_left(int keycode, t_mlx *m)
{
	if (keycode == XK_Left || keycode == XK_h)
	{
		m->f.min.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re -= (m->f.max.im - m->f.min.im) * 0.115;
	}
}

void	camera_right(int keycode, t_mlx *m)
{
	if (keycode == XK_Right || keycode == XK_l)
	{
		m->f.min.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re += (m->f.max.im - m->f.min.im) * 0.115;
	}
}

void	camera_movement(int keycode, t_mlx *m)
{
	camera_up(keycode, m);
	camera_down(keycode, m);
	camera_left(keycode, m);
	camera_right(keycode, m);
}
