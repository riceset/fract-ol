/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:41:59 by mvavasso          #+#    #+#             */
/*   Updated: 2022/09/28 08:00:26 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libraries/libft/includes/libft.h"
# include "../libraries/mlx/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

# define PI (atan(1) * 4)

#define WIDTH 900
#define HEIGHT 900

struct s_fractal
{
	void *mlx;
	void *win;

	double max_re;
	double min_re;

	double max_im;
	double min_im;
};

typedef struct s_fractal t_fractal;

#endif
