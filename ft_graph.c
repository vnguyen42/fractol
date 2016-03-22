/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/22 11:04:11 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "Libft/libft.h"
#include <stdio.h>

void	draw_line_transform(t_line *line, t_point a, t_point b
		, int point_mode)
{
	line->x = b.x - a.x;
	line->y = b.y - a.y;
	line->length = sqrt(line->x * line->x + line->y * line->y);
	if (point_mode)
		line->length = 1;
	line->addx = line->x / line->length;
	line->addy = line->y / line->length;
	line->x = a.x;
	line->y = a.y;
}

void	draw_line(t_env *env, t_point a, t_point b)
{
	int		i;
	t_line	line;

	draw_line_transform(&line, a, b, 0);
	i = 0;
	while (i < line.length)
	{
		if ((line.x + env->pos.x) < WIN_WIDTH
				&& (line.y + env->pos.y) < WIN_HEIGHT
				&& (line.x + env->pos.x) > 0
				&& (line.y + env->pos.y) > 0)
		{
			env->tmp = i;
			pixel_to_image(create_rgba(129, 169, 55, 1), env,
					line.x + env->pos.x, line.y + env->pos.y);
		}
		line.x += line.addx;
		line.y += line.addy;
		i++;
	}
}

void	draw_grid(t_env *env, int clear)
{
	if (clear)
		clear_screen(env);
	draw_julia(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
