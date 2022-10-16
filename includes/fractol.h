/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:41:59 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/16 01:06:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libraries/libft/includes/libft.h"
# include "../libraries/mlx-linux/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

# define PI (atan(1) * 4)

#define WIDTH 900.00
#define HEIGHT 900.00

struct s_complex
{
	double re;
	double im;
};

typedef struct s_complex t_complex;

struct s_fractal
{
	t_complex max;
	t_complex min;
	t_complex k;
};

typedef struct s_fractal t_fractal;


struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	t_fractal f;
};

typedef struct s_mlx t_mlx;

#endif
