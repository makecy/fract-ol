/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:10:17 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 17:45:24 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void put_pixel_row(mlx_image_t* image, int x, int y)
{
    if (x >= WIDTH)
        return;
    double a = map(x, 0, WIDTH, -2.0, 1.0);
    double b = map(y, 0, HEIGHT, -1.0, 1.0);
    t_complex c = {a, b};
    int iterations = mandelbrot(c, MAX_ITERATIONS);
    int color = get_color(iterations);
    mlx_put_pixel(image, x, y, color);
    put_pixel_row(image, x + 1, y);
}

void put_pixel(mlx_image_t* image, int y)
{
    if (y >= HEIGHT)
        return;
    put_pixel_row(image, 0, y);
    put_pixel(image, y + 1);
}

void render_mandelbrot(mlx_t *mlx)
{
    mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);
    put_pixel(image, 0);
    mlx_image_to_window(mlx, image, 0, 0);
    mlx_loop(mlx);
    mlx_delete_image(mlx, image);
}

int mandelbrot(t_complex c, int max_iterations)
{
    t_complex z = {0, 0};
	double temp;
    int iterations = 0;

    while (z.real * z.real + z.imag * z.imag <= 4.0 && iterations < max_iterations)
    {
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = temp;
        iterations++;
    }

    return iterations;
}