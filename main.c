/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:40:04 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/22 11:06:35 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_fractol.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("Utilisation: \n./fractol julia\n./fractol mandelbrot\n");
	else
	{
		if (!ft_strcmp(argv[1], "julia"))
			init_fractol(JULIA);
		else if (!ft_strcmp(argv[1], "mandelbrot"))
			init_fractol(MANDELBROT);
		else
			init_fractol(OTHER);
	}
	return (0);
}
