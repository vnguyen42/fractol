/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/22 10:54:46 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		for_julia1(t_fractal *k, t_point x)
{
	int i;

	k->newre = (double)x.x / (WIN_WIDTH / (k->x2 - k->x1)) + k->x1;
	k->newim = (double)x.y / (WIN_HEIGHT / (k->y2 - k->y1)) + k->y1;
	i = 0;
	while (i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim +
			(k->cre + k->movex);
		k->newim = 2 * k->oldre * k->oldim + (k->cim + k->movey);
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

int		for_mandelbrot(t_fractal *k, t_point x)
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
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

int		for_random(t_fractal *k, t_point x)
{
	int i;

	k->newre = 1.5 * (x.x - WIN_WIDTH / 2) /
		(0.5 * k->zoom * WIN_WIDTH) + k->movex;
	k->newim = (x.y - WIN_HEIGHT / 2) / (0.5 * k->zoom * WIN_HEIGHT) + k->movey;
	i = 0;
	while (i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

void	draw_julia(t_env *env)
{
	t_fractal	*k;
	t_point		x;
	int			i;

	x.y = env->pos.y;
	k = &env->k;
	while (x.y < WIN_HEIGHT + ft_positive(env->pos.y))
	{
		x.x = env->pos.x;
		while (x.x < WIN_WIDTH + ft_positive(env->pos.x))
		{
			if (env->fractale == JULIA)
				i = for_julia1(k, x);
			else if (env->fractale == MANDELBROT)
				i = for_mandelbrot(k, x);
			else
				i = for_burningship(k, x);
			draw_julia_color(env, k->max_iter, x, i);
			x.x++;
		}
		x.y++;
	}
}
