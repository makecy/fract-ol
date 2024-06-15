/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:55:16 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 00:03:59 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractal_options(t_fract *f)
{
	ft_putendl_fd("Wrong Input", 1);
	ft_putendl_fd("Fractal options:", 1);
	ft_putendl_fd("\t1. mandelbrot", 1);
	ft_putendl_fd("\t2. julia ", 1);
	ft_putendl_fd("\eUsage example :\t./fractol mandelbrot ", 1);
	ft_putendl_fd("\eUsage example :\t./fractol julia 0.285 0.01 ", 1);
	exit_program(1, f);
}