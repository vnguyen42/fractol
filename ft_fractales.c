/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 13:04:47 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fractal	init_julia()
{
	t_fractal k;

	k.newre = 0;
	k.newim = 0;
	k.oldre = 0;
	k.oldim = 0;
	k.movex = 0;
	k.movey = 0;
	k.zoom = 1;
	k.max_iter = 300;
	k.cre = -0.7;
	k.cim = 0.27015;
	return (k);
}

void	draw_julia(t_env *env)
{
	t_fractal k;
	t_point x;
	int i;

	x.y = 0;
	k = init_julia();
	while(x.y < WIN_HEIGHT)
	{
		x.x = 0;
		while(x.x < WIN_WIDTH)
		{
			k.newre = 1.5 * (x.x - WIN_WIDTH / 2) / (0.5 * k.zoom * WIN_WIDTH) + k.movex;
			k.newim = (x.y - WIN_HEIGHT / 2) / (0.5 * k.zoom * WIN_HEIGHT) + k.movey;
			i = 0;
			while(i < k.max_iter)
			{
				k.oldre = k.newre;
				k.oldim = k.newim;
				k.newre = k.oldre * k.oldre - k.oldim * k.oldim + k.cre;
				k.newim = 2 * k.oldre * k.oldim + k.cim;
				if((k.newre * k.newre + k.newim * k.newim) > 4)
					break;
				i++;
			}
			pixel_to_image(create_rgba(i % 256, 255, 255 * (i < k.max_iter), 1), env, x.x, x.y);
			x.x++;
		}
	x.y++;
	}
}
