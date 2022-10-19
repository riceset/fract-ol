/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:27:56 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:27:37 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int keycode, t_mlx *m)
{
	if (keycode == SCROLL_ZOOM_IN)
	{
		m->f.min.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im += (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT
			/ WIDTH;
	}
	else if (keycode == SCROLL_ZOOM_OUT)
	{
		m->f.min.re -= (m->f.max.im - m->f.min.im) * 0.115;
		m->f.max.re += (m->f.max.im - m->f.min.im) * 0.115;
		m->f.min.im -= (m->f.max.re - m->f.min.re) * 0.115;
		m->f.max.im = m->f.min.im + (m->f.max.re - m->f.min.re) * HEIGHT
			/ WIDTH;
	}
	return (0);
}
