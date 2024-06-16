/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:29:51 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 21:24:36 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include "libraries/Libft/libft.h"
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/get_next_line/get_next_line_bonus.h"
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "/Users/mstefano/42_Projects/fract-ol/MLX42/include/glad/glad.h"
#include "/Users/mstefano/42_Projects/fract-ol/MLX42/include/KHR/khrplatform.h"
#include "/Users/mstefano/42_Projects/fract-ol/MLX42/include/lodepng/lodepng.h"
#include "/Users/mstefano/42_Projects/fract-ol/MLX42/include/MLX42/MLX42_Int.h"
#include "/Users/mstefano/42_Projects/fract-ol/MLX42/src/font/font.h"

/* DIMENSIONS */
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

typedef struct s_comp
{
	double real;
	double imag;
} t_comp;

typedef struct s_fract
{
    double min_r;
    double max_r;
    double min_i;
    double max_i;
	double offsetX;
	double offsetY;
	int fractal_type;
    void *win;
    mlx_t *lib_mlx_ptr; 
} t_fract;

/* INITIALIZATION */

void	handle_args(t_fract *f, int ac, char **av);
void	init_mlx(t_fract *f);

/* MANDELBROT */
int mandelbrot(t_comp c, int max_iterations);
void render_mandelbrot(mlx_t *mlx);
void put_pixel(mlx_image_t *image, int y);

/* JULIA*/
// int	julia_shift(int x, int y, t_mlx *f);
int	julia(t_fract *f, double zr, double zi);
void	render_julia(t_fract *f);


/* UTILS */
double	map(int value, int start1, int stop1, double start2, double stop2);
double	ft_atof(const char *str);
void	fractal_options(t_fract *f);
void	clean(t_fract *f);
void	exit_program(int exit_code, t_fract *f);

/* COLOR */
int get_color(int iterations);

/* ZOOMING */
void mouse_key_event(enum mouse_key key, enum action action, enum modifier_key modifier, void *param);
void key_event(struct mlx_key_data key_data, void *param);
void mouse_event(double x, double y, void *param);


#endif