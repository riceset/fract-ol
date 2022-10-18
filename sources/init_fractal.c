/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:52 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:04 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	init_fractal(char **argv, t_fractal *f)
{
	determine_fractal(argv[1], f);
	set_complex_plane_coordinates(argv, f);
	return (true);
}
