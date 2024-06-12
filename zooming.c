/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:26:35 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 22:52:59 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void draw_rectangle(mlx_image_t *image, int x_start, int y_start, int width, int height, uint32_t color)
{
    int x;
    int y;
	x = x_start;
	y = y_start;

    while (y < y_start + height)
    {
        x = x_start;
        while (x < x_start + width)
        {
            mlx_put_pixel(image, x, y, color);
            x++;
        }
        y++;
    }
}

int compute_fractal(t_mlx *mlx, int x, int y)
{
    double zx;
	double zy;
	double cX;
	double cY;
	double tmp;
    int i;
    zx = 0;
    zy = 0;
    cX = (double)x / (mlx->zoom) + mlx->offsetX;
    cY = (double)y / (mlx->zoom) + mlx->offsetY;
    i = -1;
    while (zx * zx + zy * zy < 4 && ++i < mlx->max_iter)
    {
        tmp = zx * zx - zy * zy + cX;
        zy = 2 * zx * zy + cY;
        zx = tmp;
    }
    if (i == mlx->max_iter)
        return 0;
    else
        return (i * 255 / mlx->max_iter) << 16;
}

void render(t_mlx *mlx)
{
    int x;
	int y;
	int color;
    mlx_image_t *image;
	image = mlx_new_image(mlx->lib_mlx_ptr, WIDTH, HEIGHT);
    draw_rectangle(image, 0, 0, WIDTH, HEIGHT, 0);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            color = compute_fractal(mlx, x, y);
            mlx_put_pixel(image, x, y, color);
            x++;
        }
        y++;
    }
}

void zoom_in(t_mlx *mlx, int x, int y)
{
    double w;
    double h;
	w = (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
	h = (y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
    mlx->zoom *= 1.1;
    mlx->offsetX -= w;
    mlx->offsetY -= h;
    render(mlx);
}

void zoom_out(t_mlx *mlx, int x, int y)
{
    if (mlx->zoom > 1)
    {
        double w;
        double h;
		w = (x - WIDTH / 2) / (0.5 * mlx->zoom * WIDTH);
		h = (y - HEIGHT / 2) / (0.5 * mlx->zoom * HEIGHT);
        mlx->zoom /= 1.1;
        mlx->offsetX += w;
        mlx->offsetY += h;
		render(mlx);
    }
}

void mouse_scroll_event(int button, double x, double y, void *param)
{
    t_mlx *mlx;
    double new_zoom;
    double zoom_factor;
	mlx = (t_mlx *)param;
    if (button == 4)
        zoom_factor = 1.1;
    else
        zoom_factor = 0.9;
	new_zoom = mlx->zoom * zoom_factor;
    mlx->offsetX = (x / mlx->zoom + mlx->offsetX) - (x / new_zoom);
    mlx->offsetY = (y / mlx->zoom + mlx->offsetY) - (y / new_zoom);
    mlx->zoom = new_zoom;
    render(mlx);
}

