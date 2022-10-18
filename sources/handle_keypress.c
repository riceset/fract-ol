/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:26:59 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:02 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_keypress(int keycode, t_mlx *m)
{
	if (keycode == XK_Escape)
		close_window(keycode, m);
	zoom_on_key(keycode, m);
	camera_movement(keycode, m);
	change_color(keycode, m);
	return (0);
}
