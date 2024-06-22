/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makecy <makecy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/22 17:44:27 by makecy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fract_ol.h"

int main (int ac, char **av)
{
	(void)av;
	t_fract f;
	if (ac < 2)
		fractal_options(&f);
	clean(&f);
	handle_args(&f, ac, av);
	init_mlx(&f);
	if (f.fractal_type == 0)
		render_mandelbrot(f.lib_mlx_ptr);
	else if (f.fractal_type == 1)
		render_julia(&f);
	// mlx_hook(f.win_ptr, 2, 1L << 0, key_event, &f); TODO
	// mlx_key_hook(f.win_ptr, key_event, &f); TODO
	// mlx_mouse_hook(f.win_ptr, mouse_key_event, &f); TODO
	mlx_loop(f.lib_mlx_ptr);
	
}