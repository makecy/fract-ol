/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:34:32 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/11 00:34:46 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double map(int value, int start1, int stop1, double start2, double stop2)
{
    return start2 + (stop2 - start2) * ((value - start1) / (double)(stop1 - start1));
}