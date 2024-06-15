/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/15 23:17:37 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int main(int ac, char **av)
// {
// 	mlx_t *mlx;

//     if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
//     {
//         mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
//         if (!mlx)
//         {
//             fprintf(stderr, "Error: mlx_init failed\n");
//             return (1);
//         }
//         render_mandelbrot(mlx);
//     }
//     else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
//     {
//         mlx = mlx_init(WIDTH, HEIGHT, "Julia", false);
//         if (!mlx)
//         {
//             fprintf(stderr, "Error: mlx_init failed\n");
//             return (1);
//         }
// 		t_fract f;
// 		f.lib_mlx_ptr = mlx;
// 		f.min_r = -2.0;
// 		f.max_r = 2.0;
// 		f.min_i = -2.0;
// 		f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
// 		f.offsetX = ft_atof(av[2]);
// 		f.offsetY = ft_atof(av[3]);
// 		render_julia(&f);
// 	}
// 	else
// 	{
// 		fprintf(stderr, "Invalid arguments\n");
// 		return (1);
//     }
// 	// mlx_scroll_hook(mlx, mouse_event, mlx);
// 	// mlx_key_hook(mlx, key_event, mlx);
// 	// mlx_mouse_hook(mlx, mouse_event, mlx);
// 	mlx_loop(mlx);
//     return (0);
// }

#include "fract_ol.h"

int main (int ac, char **av)
{
	(void)av;
	t_fract f;
	if (ac < 2)
		fractal_options(&f);
	clean(&f);
	// handle_args(&f, ac, av); TODO
	// init_mlx(&f); TODO
	// render_fractal(&f); TODO
	// mlx_hook(f.win_ptr, 2, 1L << 0, key_event, &f); TODO
	// mlx_key_hook(f.win_ptr, key_event, &f); TODO
	// mlx_mouse_hook(f.win_ptr, mouse_key_event, &f); TODO
	// mlx_loop(f.lib_mlx_ptr); TODO
	
}