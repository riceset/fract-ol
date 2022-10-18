/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:27:36 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/18 18:35:43 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	check_args(int argc, char **argv)
{
	if (argc == 1)
		return (print_error("Too few arguments."));
	else if (argc > 4 || (is_mandelbrot(argv[1]) && argc > 2))
		return (print_error("Too many arguments."));
	else if (!(is_mandelbrot(argv[1]) || is_julia(argv[1])))
		return (print_error("Invalid set.\n"));
	else if (is_julia(argv[1]) && (argv[2] == NULL || argv[3] == NULL))
		return (print_error("Invalid constant (K) value.\n"));
	return (true);
}
