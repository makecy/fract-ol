/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:29:51 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 22:47:57 by mstefano         ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

typedef struct s_mlx
{
    mlx_t *lib_mlx_ptr; 
    void *win_ptr;
    double zoom;
    double offsetX;
    double offsetY;
    int max_iter;
    int mouse_x;
    int mouse_y;
} t_mlx;

/* MANDELBROT */
int mandelbrot(t_complex c, int max_iterations);
void render_mandelbrot(mlx_t *mlx);
void put_pixel(mlx_image_t *image, int y);

/* UTILS */
double map(int value, int start1, int stop1, double start2, double stop2);

/* COLOR */
int get_color(int iterations);

/* ZOOMING */
int compute_fractal(t_mlx *mlx, int x, int y);
void render(t_mlx *mlx);
void zoom_out(t_mlx *mlx, int x, int y);
void zoom_in(t_mlx *mlx, int x, int y);
void mouse_scroll_event(int button, double x, double y, void *param);
void draw_rectangle(mlx_image_t *image, int x_start, int y_start, int width, int height, uint32_t color);

#endif