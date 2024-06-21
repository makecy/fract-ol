/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makecy <makecy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:21:10 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/21 19:07:20 by makecy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	handle_args(t_fract *f, int ac, char **av)
{
	(void)ac;
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		f->fractal_type = 0;
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		f->fractal_type = 1;
		f->offsetX = ft_atof(av[1]);
		f->offsetY = ft_atof(av[2]);
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void init_mlx(t_fract *f)
{
	f->lib_mlx_ptr = mlx_init(WIDTH, HEIGHT, "Fract'ol", 0);
	if (f->lib_mlx_ptr == NULL)
	{
		ft_putendl_fd("Error: mlx_init failed", 1);;
		exit_program(1, f);
	}
	f->win = mlx_new_image(f->lib_mlx_ptr, WIDTH, HEIGHT);
	if(!f->win)
	{
		ft_putendl_fd("Error: mlx_new_image failed", 1);
		exit_program(1, f);
	}
}