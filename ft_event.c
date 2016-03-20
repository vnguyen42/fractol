/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:47:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/20 19:10:15 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_hauteur_animation(void *param)
{
	t_env *env;

	env = param;
	if (env->ft_hauteur_animation)
	{
		if (env->cre > 0.2)
			env->ft_hauteur_animation_going = 0;
		else if (env->cre < -1.0
				&& env->ft_hauteur_animation_going == 0)
			env->ft_hauteur_animation_going = 1;
		if (env->ft_hauteur_animation_going)
		{
			env->cre += 0.01;
			env->cim += 0.01;
		}
		else
		{
			env->cre -= 0.01;
			env->cim -= 0.01;
		}
	}
	printf("cre %f\n", env->cre);
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

int		ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	ft_color_mode(keycode, env);
	printf("keycode %d\n", keycode);
	if (keycode == 123)
		env->movex -= 0.0153 * env->zoom;
	if (keycode == 124)
		env->movex += 0.0153 * env->zoom;
		//env->pos.x -= 20 * (env->zoom);
	if (keycode == 125)
		env->movey += 0.0153 * env->zoom;
		//env->pos.y -= 20 * (env->zoom);
	if (keycode == 126)
		env->movey -= 0.0153 * env->zoom;
	if (keycode == 69)
		env->zoom += 0.4 * env->zoom;
	if (keycode == 78)
		env->zoom -= 0.4 * env->zoom;
	if (keycode == 53)
		exit(0);
	return (1);
}
