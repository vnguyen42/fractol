/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:19:31 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/21 18:32:35 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	zoom_in(t_env *env, double xspan, double yspan, t_double new)
{
	double tmp;

	if (env->max_iter < 300)
		env->max_iter += 4;
	tmp = env->k.x1;
	env->k.x1 = (new.x + (env->k.x2 + env->k.x1) / 2) / 2 - (xspan * 0.4);
	env->k.x2 = (new.x + (env->k.x2 + tmp) / 2) / 2 + (xspan * 0.4);
	tmp = env->k.y1;
	env->k.y1 = (new.y + (env->k.y2 + env->k.y1) / 2) / 2 - (yspan * 0.4);
	env->k.y2 = (new.y + (env->k.y2 + tmp) / 2) / 2 + (yspan * 0.4);
}

void	zoom_out(t_env *env, double xspan, double yspan)
{
	env->k.x1 = env->k.x1 - (xspan * 0.52);
	env->k.x2 = env->k.x2 + (xspan * 0.52);
	env->k.y1 = env->k.y1 - (yspan * 0.52);
	env->k.y2 = env->k.y2 + (yspan * 0.52);
}
