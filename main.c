/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:40:04 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 16:22:57 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_fractol.h"

int		main(int argc, char **argv)
{
	int nomouse;

	nomouse = 0;
	if (argc < 2)
		ft_putstr("Utilisation: \n./fractol julia\n./fractol mandelbrot\n");
	else
	{
		if (argc > 2 && argv[2] && !ft_strcmp(argv[2], "nomouse"))
			nomouse = 1;
		if (!ft_strcmp(argv[1], "julia"))
				init_fractol(JULIA, nomouse);
		else if (!ft_strcmp(argv[1], "mandelbrot"))
			init_fractol(MANDELBROT, nomouse);
		else
			init_fractol(OTHER, nomouse);
	}
	return (0);
}
