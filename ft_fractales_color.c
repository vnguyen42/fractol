/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:27:49 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/20 19:34:10 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	draw_julia_color(t_env *env, int max_iter, t_point x, int i)
{
	if (env->color_mode == 1)
	{
		pixel_to_image(create_rgba((i) % 8 * 32, i % 15 * 16
					, i % 32 * 8 * (i < max_iter), 1), env, x.x,
				x.y + env->pos.y);
	}
	else if (env->color_mode == 2)
	{
		pixel_to_image(create_rgba(0, 0
					, i % 32 * 8 * (i < max_iter), 1), env, x.x,
				x.y);
	}
	else if (env->color_mode == 3)
		pixel_to_image(create_rgba(128, i % 32 * 8 * (i < max_iter),
					 0, i % 32 * 8 * (i < max_iter)), env, x.x,
				x.y);
}
