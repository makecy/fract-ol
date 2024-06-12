/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:46:28 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 21:20:39 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int main(int ac, char **av)
{
    mlx_t *mlx;

    if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
    {
        mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
        if (!mlx)
        {
            fprintf(stderr, "Error: mlx_init failed\n");
            return (1);
        }
        render_mandelbrot(mlx);
        mlx_scroll_hook(mlx, mouse_scroll_event, mlx);
    }
    else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
    {
        mlx = mlx_init(WIDTH, HEIGHT, "Julia", false);
        if (!mlx)
        {
            fprintf(stderr, "Error: mlx_init failed\n");
            return (1);
        }
        /* render_julia(); // To be implemented */
        mlx_scroll_hook(mlx, mouse_scroll_event, mlx);
    }
    else
    {
        fprintf(stderr, "Invalid arguments\n");
        return (1);
    }
    mlx_loop(mlx);
    return (0);
}