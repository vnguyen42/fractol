/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 12:22:34 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fractal	init_julia()
{
	t_fractal k;

	k.cre = -0.7;
	k.cim = 0.27015;
	k.newre = 0;
	k.newim = 0;
	k.oldre = 0;
	k.oldim = 0;
	k.movex = 0;
	k.movey = 0;
	k.zoom = 1;
	k.max_iter = 300;
	return (k);
}

void	draw_julia(t_env *env)
{
	t_fractal k;
	double zoom = 1, moveX = 0, moveY = 0;
	int maxIterations = 300;
	int w = 1000, h = 1000;

	k.cre = -0.7;
	k.cim = 0.27015;

	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			k.newre = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			k.newim = (y - h / 2) / (0.5 * zoom * h) + moveY;
			int i;
			for(i = 0; i < maxIterations; i++)
			{
				k.oldre = k.newre;
				k.oldim = k.newim;
				k.newre = k.oldre * k.oldre - k.oldim * k.oldim + k.cre;
				k.newim = 2 * k.oldre * k.oldim + k.cim;
				if((k.newre * k.newre + k.newim * k.newim) > 4) break;
			}
			pixel_to_image(create_rgba(i % 256, 255, 255 * (i < maxIterations), 1), env, x, y);
		}
	}
}
