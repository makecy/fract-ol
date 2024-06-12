/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:35:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/12 22:56:36 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int ft_pixel(int red, int green, int blue, int alpha)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int get_color(int iterations)
{
	int red;
	int blue;
	int green;
    if (iterations == MAX_ITERATIONS)
        return ft_pixel(0, 0, 0, 255);
    else
    {
        red = (iterations * 5) % 255;
        blue = (iterations * 10) % 255;
        green = (iterations * 20) % 255;
        return ft_pixel(red, green, blue, 255);
    }
}