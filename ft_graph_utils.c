/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:53:42 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/18 15:58:33 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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

unsigned long create_rgba(int r, int g, int b, int a)
{   
	return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
		+ (a & 0xff);
}
