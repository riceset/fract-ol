/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:50:23 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/16 08:50:28 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libraries/ft_printf/includes/ft_printf.h"
# include "../libraries/libft/includes/colors.h"
# include "../libraries/libft/includes/libft.h"
# include "../libraries/mlx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define PI (atan(1) * 4)

# define WIDTH 900.00
# define HEIGHT 900.00

# define SUCCESS 0
# define ERROR 1

# define SCROLL_ZOOM_IN 4
# define SCROLL_ZOOM_OUT 5

enum						e_fractal_name
{
	MANDELBROT,
	JULIA
};

typedef enum e_fractal_name	t_fractal_name;

struct						s_complex
{
	double					re;
	double					im;
};

typedef struct s_complex	t_complex;

struct						s_fractal
{
	t_fractal_name			name;
	t_complex				max;
	t_complex				min;
	t_complex				k;
};

typedef struct s_fractal	t_fractal;

struct						s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						color;
	t_fractal				f;
};

typedef struct s_mlx		t_mlx;

#endif
