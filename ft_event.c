/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:47:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/18 16:56:20 by vnguyen          ###   ########.fr       */
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

int		ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	printf("keycode %d\n", keycode);
	if (keycode == 123)
		env->movex -= 0.0553;
	if (keycode == 124)
		env->pos.x -= 50 / env->zoom;
	if (keycode == 125)
		env->pos.y -= 50 / env->zoom;
	if (keycode == 126)
		env->movey -= 0.0553;
	if (keycode == 69)
		env->zoom += 0.4;
	if (keycode == 78)
		env->zoom -= 0.4;
	draw_grid(env, 1);	
	if (keycode == 53)
		exit(0);
	return (1);
}
