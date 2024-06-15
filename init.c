/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:21:10 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 00:18:34 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
void	handle_args(t_fract *f, int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		f->fractal_type = 0;
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		f->fractal_type = 1;
}

void init_mlx(t_fract *f)
{
	f->lib_mlx_ptr = mlx_init(WIDTH, HEIGHT, "Fract'ol", 0);
if (f->lib_mlx_ptr == NULL)
	{
		ft_putendl_fd("Error: mlx_init failed", 1);;
		exit_program(1, f);
	}
	f->win_ptr = mlx_new_image(f->lib_mlx_ptr, WIDTH, HEIGHT);
	if(!f->win_ptr)
	{
		ft_putendl_fd("Error: mlx_new_image failed", 1);
		exit_program(1, f);
	}
}