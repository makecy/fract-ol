/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:09:41 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 21:25:25 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// int	julia_shift(int x, int y, t_mlx *f)
// {
//     f->offsetX = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
//     f->offsetY = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
//     render_julia(f);
//     return (0);
// }

int	julia(t_fract *f, double zr, double zi)
{
    int		n;
    double	tmp;

    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zi * zi + zr * zr) > 4.0)
            break ;
        tmp = 2 * zr * zi + f->offsetY;
        zr = zr * zr - zi * zi + f->offsetX;
        zi = tmp;
        n++;
    }
    return (n);
}

void	render(t_fract *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void render_julia(t_fract *f)
{
	int x;
	int y;
	double zr;
	double zi;
	int nb_iter;
	
	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			zr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			zi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = julia(f, zr, zi);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, 0, 0);
}

