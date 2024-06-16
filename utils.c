/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:34:32 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/16 20:52:03 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	clean(t_fract *f)
{
    f->lib_mlx_ptr = NULL;
    f->win = NULL;
    f->offsetX = 0.0;
    f->offsetY = 0.0;
    f->min_r = 0.0;
    f->max_r = 0.0;
    f->min_i = 0.0;
    f->max_i = 0.0;
}

double map(int value, int start1, int stop1, double start2, double stop2)
{
    return start2 + (stop2 - start2) * ((value - start1) / (double)(stop1 - start1));
}

double ft_atof(const char *str)
{
    double result = 0.0;
    double sign = 1.0;
    double decimal_place = 0.1;
	
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    if (*str == '-')
    {
        sign = -1.0;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            result += decimal_place * (*str - '0');
            decimal_place *= 0.1;
            str++;
        }
    }

    return sign * result;
}

void exit_program(int exit_code, t_fract *f)
{
	if (!f)
		exit(exit_code);
	if(f->lib_mlx_ptr && f->win)
		mlx_delete_image(f->lib_mlx_ptr, f->win);
	exit(exit_code);
}