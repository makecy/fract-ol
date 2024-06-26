/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:35:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/17 16:10:45 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int ft_pixel(int red, int green, int blue, int alpha)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int get_color(int iterations)
{
	int red = (iterations * 5) % 255;;
	int blue = (iterations * 10) % 255;;
	int green = (iterations * 20) % 255;;
    if (iterations == MAX_ITERATIONS)
		return 0x00000000;
    else
        return ft_pixel(red, green, blue, 255);
}