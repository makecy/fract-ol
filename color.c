/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:35:45 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/11 00:36:05 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int get_color(int iterations)
{
	if (iterations == MAX_ITERATIONS)
		return 0x000000;
	else
		return 0xFFFFFF;
}