/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/20 19:46:29 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fractal	init_julia(t_env *env)
{
	t_fractal k;

	k.newre = 0;
	k.newim = 0;
	k.oldre = 0;
	k.oldim = 0;
	k.movex = env->movex;
	k.movey = env->movey;
	k.zoom = env->zoom;
	k.max_iter = env->max_iter;
	k.cre = env->cre;
	k.cim = env->cim;
	return (k);
}

int		for_julia1(t_fractal *k, t_point x)
{
	int i;

	k->newre = 1.5 * (x.x - WIN_WIDTH / 2) / (0.5 * k->zoom * WIN_WIDTH) + k->movex;
	k->newim = (x.y - WIN_HEIGHT / 2) / (0.5 * k->zoom * WIN_HEIGHT) + k->movey;
	i = 0;
	while(i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break;
		i++;
	}
	return (i);
}

int     for_mandelbrot(t_fractal *k, t_point x)
{
	int i;

	k->cre = 1.5 * (x.x - WIN_WIDTH / 2) / (0.5 * k->zoom * WIN_WIDTH) + k->movex;
	k->cim = (x.y - WIN_HEIGHT / 2) / (0.5 * k->zoom * WIN_HEIGHT) + k->movey;
	k->newre = k->newim = k->oldre = k->oldim = 0;
	i = 0;
	while(i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre -  k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break;
		i++;
	}
	return (i);
}

int     for_random(t_fractal *k, t_point x)
{
	int i;

	k->newre = 1.5 * (x.x - WIN_WIDTH / 2) / (0.5 * k->zoom * WIN_WIDTH) + k->movex;
	k->newim = (x.y - WIN_HEIGHT / 2) / (0.5 * k->zoom * WIN_HEIGHT) + k->movey;
	i = 0;
	while(i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + k->cre;
		k->newim = 2 * k->oldre * k->oldim + k->cim;
		if ((k->newre * k->newre + k->newim * k->newim) > 4)
			break;
		i++;
	}
	return (i);
}

void draw_branch(t_env *env, int depth,
		float x, float y, float length, float theta,
		float length_scale, float dtheta)
{
	float x1 = (float)(x + length * Math.Cos(theta));
	float y1 = (float)(y + length * Math.Sin(theta));

	gr.DrawLine(pen, x, y, x1, y1);
	if (depth > 1)
	{
		draw_branch(gr, pen, depth - 1, x1, y1, length * length_scale,
			theta + dtheta, length_scale, dtheta);
		draw_branch(gr, pen, depth - 1, x1, y1,
			length * length_scale, theta - dtheta, length_scale, dtheta);
	}
}
void	draw_julia(t_env *env)
{
	t_fractal k;
	t_point x;
	int i;

	x.y = env->pos.y;
	k = init_julia(env);
	while(x.y < WIN_HEIGHT + ft_positive(env->pos.y))
	{
		x.x = env->pos.x;
		while(x.x < WIN_WIDTH + ft_positive(env->pos.x))
		{
			if (env->fractale == JULIA)
				i = for_julia1(&k, x);
			else if (env->fractale == MANDELBROT)
				i = for_mandelbrot(&k, x);
			else
				i = for_random(&k, x);
			draw_julia_color(env, k.max_iter, x, i);
			//pixel_to_image(create_rgba((i) % 8 * 32, i % 15 * 16
			//			, i % 32 * 8 * (i < k.max_iter), 1), env, x.x + env->pos.x,
			//		x.y + env->pos.y);
			x.x++;
		}
		x.y++;
	}
}
