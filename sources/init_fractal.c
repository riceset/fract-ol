/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:52 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 22:04:04 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	init_fractal(char **argv, t_fractal *f)
{
	bool	is_valid;

	is_valid = true;
	determine_fractal(argv[1], f);
	set_complex_coordinates(argv, f, &is_valid);
	if (is_valid)
		return (true);
	return (print_error("Invalid constant (K) value."));
}
