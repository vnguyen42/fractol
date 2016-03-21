/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/21 19:31:43 by vnguyen          ###   ########.fr       */
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

int		for_julia1(t_fractal *k, t_point x)
{
	int i;

	//k->newre = 1.5 * (x.x - WIN_WIDTH / 2) / (0.5 * k->zoom * WIN_WIDTH) + k->movex;
	//k->newim = (x.y - WIN_HEIGHT / 2) / (0.5 * k->zoom * WIN_HEIGHT) + k->movey;
	k->newre = (double)x.x / (WIN_WIDTH / (k->x2 - k->x1)) + k->x1;
	k->newim = (double)x.y / (WIN_HEIGHT / (k->y2 - k->y1)) + k->y1;
	i = 0;
	while(i < k->max_iter)
	{
		k->oldre = k->newre;
		k->oldim = k->newim;
		k->newre = k->oldre * k->oldre - k->oldim * k->oldim + (k->cre + k->movex);
		k->newim = 2 * k->oldre * k->oldim + (k->cim + k->movey);
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
		double x, double y, double length, double theta,
		double length_scale, double dtheta)
{
	double x1 = (double)(x + length * cos(theta));
	double y1 = (double)(y + length * sin(theta));

	draw_line(env, rt_point(x,y), rt_point(x1, y1));
	if (depth > 1)
	{
		draw_branch(env, depth - 1, x1, y1, length * length_scale,
			theta + dtheta, length_scale, dtheta);
		draw_branch(env, depth - 1, x1, y1,
			length * length_scale, theta - dtheta, length_scale, dtheta);
	}
}
void	draw_julia(t_env *env)
{
	t_fractal *k;
	t_point x;
	int i;

	x.y = env->pos.y;
	k = &env->k;
	if (env->fractale != JULIA && env->fractale != MANDELBROT)
	{
		draw_branch(env, 13, 300.0, 600.0, 150.0, 10.0, 0.3, 60.0);
		return;
	}
	while(x.y < WIN_HEIGHT + ft_positive(env->pos.y))
	{
		x.x = env->pos.x;
		while(x.x < WIN_WIDTH + ft_positive(env->pos.x))
		{
			if (env->fractale == JULIA)
				i = for_julia1(k, x);
			else if (env->fractale == MANDELBROT)
				i = for_mandelbrot(k, x);
			else
				i = for_random(k, x);
			draw_julia_color(env, k->max_iter, x, i);
			x.x++;
		}
		x.y++;
	}
}
