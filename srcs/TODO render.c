/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TODO render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:10:17 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/17 16:10:13 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void put_pixel_row(mlx_image_t *image, int x, int y)
{
	double a;
	double b;
	t_comp c;
	int iterations;
	int color;
	if (x >= WIDTH)
		return;
	a = map(x, 0, WIDTH, -2.0, 1.0);
	b = map(y, 0, HEIGHT, -1.0, 1.0);
	c = (t_comp){a, b,};
	iterations = mandelbrot(c, MAX_ITERATIONS);
	color = get_color(iterations);
	mlx_put_pixel(image, x, y, color);
	put_pixel_row(image, x + 1, y);
}


void put_pixel(mlx_image_t *image, int y)
{
	if (y >= HEIGHT)
		return;
	put_pixel_row(image, 0, y);
	put_pixel(image, y + 1);
}

void render_mandelbrot(mlx_t *mlx)
{
	mlx_image_t *image;
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	put_pixel(image, 0);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
}