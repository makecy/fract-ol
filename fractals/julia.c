/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:06:16 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/17 16:07:10 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	julia(t_fract *f, double zr, double zi)
{
    int		n;
    double	tmp;

    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zi * zi + zr * zr) > 4.0)
            break ;
        tmp = 2 * zr * zi + f->offsetY;
        zr = zr * zr - zi * zi + f->offsetX;
        zi = tmp;
        n++;
    }
    return (n);
}