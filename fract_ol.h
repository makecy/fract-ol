/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:29:51 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 17:02:35 by mstefano         ###   ########.fr       */
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
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

/* MANDELBROT */
int mandelbrot(t_complex c, int max_iterations);
void render_mandelbrot(mlx_t *mlx);
void put_pixel(mlx_image_t* image, int x, int y);

/* UTILS */
double map(int value, int start1, int stop1, double start2, double stop2);


/* COLOR */
int get_color(int iterations);


#endif