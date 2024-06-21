/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:07:29 by mstefano          #+#    #+#             */
/*   Updated: 2024/06/17 16:07:55 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int mandelbrot(t_comp c, int max_iterations)
{
	t_comp z = {0, 0,};
	double temp;
	int iterations;
	iterations = 0;

	while (z.real * z.real + z.imag * z.imag <= 4.0 && iterations < max_iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		iterations++;
	}
	return iterations;
}