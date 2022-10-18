/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:24:14 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:10 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_color(t_mlx *m, int i, int x, int y)
{
	if (m->color % 5 == 0)
		color_1(m, i, x, y);
	else if (m->color % 5 == 1)
		color_2(m, i, x, y);
	else if (m->color % 5 == 2)
		color_3(m, i, x, y);
	else if (m->color % 5 == 3)
		color_4(m, i, x, y);
	else if (m->color % 5 == 4)
		color_5(m, i, x, y);
}
