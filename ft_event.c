/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:00:47 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 16:20:49 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <math.h>
#include <stdlib.h>

void	ft_hauteur_animation(void *param)
{
	t_env *env;

	env = param;
	if (env->ft_hauteur_animation)
	{
		if (env->k.cre > 0.2)
			env->ft_hauteur_animation_going = 0;
		else if (env->k.cre < -1.0
				&& env->ft_hauteur_animation_going == 0)
			env->ft_hauteur_animation_going = 1;
		if (env->ft_hauteur_animation_going)
		{
			env->k.cre += 0.01;
			env->k.cim += 0.01;
		}
		else
		{
			env->k.cre -= 0.01;
			env->k.cim -= 0.01;
		}
	}
}

void	ft_color_mode(int keycode, t_env *env)
{
	if (keycode == 83)
		env->color_mode = 1;
	else if (keycode == 84)
		env->color_mode = 2;
	else if (keycode == 85)
		env->color_mode = 3;
	else if (keycode == 256)
		env->max_iter += 5;
	else if (keycode == 257)
		env->max_iter -= 5;
	else if (keycode == 21)
	{
		if (env->ft_hauteur_animation)
			env->ft_hauteur_animation = 0;
		else
			env->ft_hauteur_animation = 1;
	}
}

int		ft_expose_handler(int x, int y, void *param)
{
	t_env *env;

	env = param;
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT
			&& !env->nomouse)
	{
		env->k.cre = (double)x / WIN_WIDTH;
		env->k.cim = (double)y / WIN_HEIGHT;
	}
	return (1);
}

int		ft_mouse_handler(int keycode, int x, int y, void *param)
{
	t_env		*env;
	t_double	new;
	double		xspan;
	double		yspan;

	env = param;
	new.x = x / (WIN_WIDTH / (env->k.x2 - env->k.x1)) + env->k.x1;
	new.y = y / (WIN_HEIGHT / (env->k.y2 - env->k.y1)) + env->k.y1;
	xspan = env->k.x2 - env->k.x1;
	yspan = env->k.y2 - env->k.y1;
	if (keycode == 4)
		zoom_in(env, xspan, yspan, new);
	if (keycode == 6)
		zoom_out(env, xspan, yspan);
	return (1);
}

int		ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	ft_color_mode(keycode, env);
	if (keycode == 123)
		env->k.x1 -= 0.0153 * env->zoom;
	if (keycode == 124)
		env->k.x1 += 0.0153 * env->zoom;
	if (keycode == 125)
		env->k.y1 += 0.0153 * env->zoom;
	if (keycode == 126)
		env->k.y1 -= 0.0153 * env->zoom;
	if (keycode == 69)
		env->zoom += 0.4 * env->zoom;
	if (keycode == 78)
		env->zoom -= 0.4 * env->zoom;
	if (keycode == 53)
		exit(0);
	return (1);
}
