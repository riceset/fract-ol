/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalized_with_success.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:27:20 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:01 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	finalized_with_success(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_display(m->mlx);
	mlx_loop_end(m->mlx);
	free(m->mlx);
	return (SUCCESS);
}
