/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:30 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:35:56 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	is_mandelbrot(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name,
			"mandelbrot") == 0)
		return (true);
	return (false);
}

bool	is_julia(char *name)
{
	if (ft_strcmp(name, "Julia") == 0 || ft_strcmp(name, "julia") == 0)
		return (true);
	return (false);
}

void	determine_fractal(char *name, t_fractal *f)
{
	if (is_mandelbrot(name))
		f->name = MANDELBROT;
	else if (is_julia(name))
		f->name = JULIA;
}
