/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_burningship.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:43:39 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/22 10:55:28 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			for_burningship(t_fractal *k, t_point x)
{
	int i;

	k->cre = (double)x.x / (WIN_WIDTH / (k->x2 - k->x1)) + k->x1;
	k->cim = (double)x.y / (WIN_HEIGHT / (k->y2 - k->y1)) + k->y1;
	k->newre = 0;
	k->newim = 0;
	k->oldre = 0;
	k->oldim = 0;
	i = 0;
	while (i < k->max_iter)
	{
		k->oldre = fabs(k->newre);
		k->oldim = fabs(k->newim);
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

t_fractal	init_julia(t_env *env)
{
	t_fractal k;

	k.newre = 0;
	k.newim = 0;
	k.oldre = 0;
	k.oldim = 0;
	k.movex = 0.0;
	k.movey = 0.0;
	k.zoom = env->zoom;
	k.max_iter = env->max_iter;
	k.cre = env->cre;
	k.cim = env->cim;
	k.x1 = -3;
	k.x2 = -3 + 6 * WIN_WIDTH / WIN_HEIGHT;
	k.y1 = -3;
	k.y2 = 3;
	return (k);
}
