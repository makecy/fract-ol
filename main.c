/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:02 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 00:02:08 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fract_ol.h"

int main (int ac, char **av)
{
	(void)av;
	t_fract f;
	if (ac < 2)
		fractal_options(&f);
	clean(&f);
	handle_args(&f, ac, av);
	// init_mlx(&f); TODO
	// render_fractal(&f); TODO
	// mlx_hook(f.win_ptr, 2, 1L << 0, key_event, &f); TODO
	// mlx_key_hook(f.win_ptr, key_event, &f); TODO
	// mlx_mouse_hook(f.win_ptr, mouse_key_event, &f); TODO
	// mlx_loop(f.lib_mlx_ptr); TODO
	
}