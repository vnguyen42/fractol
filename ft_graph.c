/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/15 16:08:16 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "Libft/libft.h"
#include "read_grid.h"
#include <stdio.h>

int		ft_altitude_color(t_env *env, t_point a
		, t_point b, t_line line)
{
	return (env->color - (a.z * 100) -
			(env->tmp * ((ft_int_diff(a.z, b.z) * 20000) / line.length)));
}

void	draw_line_transform(t_line *line, t_point a, t_point b)
{
	line->x = b.x - a.x;
	line->y = b.y - a.y;
	line->length = sqrt(line->x * line->x + line->y * line->y);
	line->addx = line->x / line->length;
	line->addy = line->y / line->length;
	line->x = a.x;
	line->y = a.y;
}

void	draw_line(t_env *env, t_point a, t_point b)
{
	int		i;
	t_line	line;

	draw_line_transform(&line, a, b);
	i = 0;
	while (i < line.length)
	{
		if ((line.x + env->pos.x) < WIN_WIDTH
				&& (line.y + env->pos.y) < WIN_HEIGHT
				&& (line.x + env->pos.x) > 0
				&& (line.y + env->pos.y) > 0)
		{
			env->tmp = i;
			pixel_to_image(ft_altitude_color(env, a, b, line), env,
					line.x + env->pos.x, line.y + env->pos.y);
		}
		line.x += line.addx;
		line.y += line.addy;
		i++;
	}
}

void	point_360_drawing(t_env *env, int **tab, t_point pos)
{
	t_point a;
	t_point b;

	a.x = pos.x;
	a.y = pos.y;
	a.z = tab[a.y][a.x] * env->hauteur;
	b.x = (pos.x);
	b.y = (pos.y + 1);
	b.z = tab[b.y][b.x] * env->hauteur;
	if (tab[pos.y + 2] != 0 && tab[pos.y + 1][pos.x] != -42)
		draw_line(env, ft_rotation(env, ft_projection(env, a, 0.5),
						env->rotation), ft_rotation(env,
						ft_projection(env, b, 0.5), env->rotation));
	b.y--;
	b.x++;
	b.z = tab[b.y][b.x];
	if (tab[pos.y] != 0 && tab[pos.y][pos.x + 1] != -42)
		draw_line(env, ft_rotation(env, ft_projection(env, a, 0.5),
						env->rotation), ft_rotation(env,
						ft_projection(env, b, 0.5), env->rotation));
}

void	draw_grid(t_env *env, int clear)
{
	t_point p;

	if (clear)
		clear_screen(env);
	p.x = 0;
	p.y = 0;
	p.z = 0;
	while (env->tab[p.y] != 0 && p.y < env->dimensions.y - 1)
	{
		p.x = 0;
		while (env->tab[p.y][p.x] != -42)
		{
			point_360_drawing(env, env->tab, p);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
