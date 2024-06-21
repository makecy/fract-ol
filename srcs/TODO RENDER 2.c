/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TODO RENDER 2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:09:41 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/17 16:10:16 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void render_julia(t_fract *f)
{
    int x = 0;
	int y = 0;
	int i = 0;
    double zr, zi;
    mlx_image_t *img;
    int color = 0;

    img = mlx_new_image(f->lib_mlx_ptr, WIDTH, HEIGHT);
	while (x < WIDTH)
    {
		y = 0;
		while (y < HEIGHT)
        {
            zr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
            zi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
            i = julia(f, zr, zi);
            if (i == MAX_ITERATIONS)
                mlx_put_pixel(img, x, y, 0);
            else
            {
                color = get_color(i);
                mlx_put_pixel(img, x, y, color);
            }
			y++;
        }
		x++;
    }
    mlx_image_to_window(f->lib_mlx_ptr, img, 0, 0);
    mlx_delete_image(f->lib_mlx_ptr, img);
}

