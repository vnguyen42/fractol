/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:47:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/15 16:03:44 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <math.h>
#include <stdlib.h>

void	ft_hauteur_animation(void *param)
{
	t_env *env;

	env = param;
	if (env->ft_hauteur_animation)
	{
		if (env->hauteur > 20)
			env->ft_hauteur_animation_going = 0;
		else if (env->hauteur < -20
				&& env->ft_hauteur_animation_going == 0)
			env->ft_hauteur_animation_going = 1;
		if (env->ft_hauteur_animation_going)
			env->hauteur += 0.2;
		else
			env->hauteur -= 0.2;
	}
}

void	ft_key_handler2(int keycode, t_env *env)
{
	if (keycode == 257)
		env->rotation -= 0.1;
	else if (keycode == 256)
		env->rotation += 0.1;
	else if (keycode == 69)
		env->grid_space += 2;
	else if (keycode == 78 && env->grid_space >= 2)
		env->grid_space -= 2;
	else if (keycode == 126)
		env->pos.y -= 25;
	else if (keycode == 125)
		env->pos.y += 25;
	else if (keycode == 123)
		env->pos.x -= 25;
	else if (keycode == 124)
		env->pos.x += 25;
	else if (keycode == 19)
		env->hauteur += 1;
	else if (keycode == 18)
		env->hauteur -= 1;
}

int		ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	ft_key_handler2(keycode, env);
	if (keycode == 20)
	{
		if (env->ft_hauteur_animation)
			env->ft_hauteur_animation = 0;
		else
			env->ft_hauteur_animation = 1;
	}
	if (keycode == 257 || keycode == 256 || keycode == 18
			|| keycode == 19 || keycode == 69 || keycode == 78
			|| (keycode >= 123 && keycode <= 126))
		draw_grid(param, 1);
	if (keycode == 53)
		exit(0);
	return (1);
}
