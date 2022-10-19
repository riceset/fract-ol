/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:50:23 by tkomeno           #+#    #+#             */
/*   Updated: 2022/10/19 16:36:21 by tkomeno          ###   ########.fr       */
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

double						ft_atof(char *str, bool *is_valid);
void						pixel_put(t_mlx *data, int x, int y, int color);
bool						print_error(char *message);
void						set_mandelbrot_coord(t_fractal *f);
void						set_julia_coord(char **argv, t_fractal *f,
								bool *is_valid);
void						set_complex_coord(char **argv, t_fractal *f,
								bool *is_valid);
bool						init_mlx(t_mlx *m);
bool						is_mandelbrot(char *name);
bool						is_julia(char *name);
void						determine_fractal(char *name, t_fractal *f);
bool						init_fractal(char **argv, t_fractal *f);
double						square(double x);
int							julia(t_mlx *m, t_complex z);
int							mandelbrot(t_complex c);
void						draw_fractal(t_mlx *m);
int							draw_and_put_image(t_mlx *m);
int							close_window_esc(int keycode, t_mlx *m);
int							close_window_x(t_mlx *m);
void						zoom_in_on_key(int keycode, t_mlx *m);
void						zoom_out_on_key(int keycode, t_mlx *m);
void						zoom_on_key(int keycode, t_mlx *m);
void						camera_up(int keycode, t_mlx *m);
void						camera_down(int keycode, t_mlx *m);
void						camera_left(int keycode, t_mlx *m);
void						camera_right(int keycode, t_mlx *m);
void						camera_movement(int keycode, t_mlx *m);
void						change_color(int keycode, t_mlx *m);
int							handle_keypress(int keycode, t_mlx *m);
int							finalized_with_success(t_mlx *m);
bool						check_args(int argc, char **argv);
int							mouse_hook(int keycode, t_mlx *m);

void						set_color(t_mlx *m, int i, int x, int y);
void						color_1(t_mlx *m, int i, int x, int y);
void						color_2(t_mlx *m, int i, int x, int y);
void						color_3(t_mlx *m, int i, int x, int y);
void						color_4(t_mlx *m, int i, int x, int y);
void						color_5(t_mlx *m, int i, int x, int y);

#endif
