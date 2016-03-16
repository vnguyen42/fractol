/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:53:42 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/15 16:14:06 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	clear_screen(t_env *env)
{
	t_point p;

	mlx_clear_window(env->mlx, env->win);
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			pixel_to_image(0x00000000, env,
					p.x, p.y);
			p.x++;
		}
		p.y++;
	}
}
