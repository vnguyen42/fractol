/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:41:08 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/15 16:09:47 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <math.h>

t_point		ft_projection(t_env *env, t_point p, float cte)
{
	float	x;
	float	y;
	float	z;
	t_point	projected_point;

	z = p.z / 6.5;
	x = p.x - cte * z;
	y = p.y - (cte / 2) * z;
	projected_point.x = x * env->grid_space;
	projected_point.y = y * env->grid_space;
	projected_point.z = z;
	return (projected_point);
}

t_point		ft_rotation(t_env *env, t_point p, float angle)
{
	t_point	rotated_point;
	t_point	new_point;
	float	s;
	float	c;

	(void)(env);
	rotated_point = p;
	s = sin(angle);
	c = cos(angle);
	new_point.x = rotated_point.x * c - rotated_point.y * s;
	new_point.y = rotated_point.x * s + rotated_point.y * c;
	rotated_point.x = new_point.x;
	rotated_point.y = new_point.y;
	return (rotated_point);
}

int			ft_int_diff(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

void		pixel_to_image(unsigned long color, t_env *val, int x, int y)
{
	char	*image;
	int		bpp;
	int		size_line;
	int		endian;

	image = mlx_get_data_addr(val->img, &bpp, &size_line, &endian);
	val->r = ((color & 0xFF0000) >> 16);
	val->g = ((color & 0xFF00) >> 8);
	val->b = ((color & 0xFF));
	image[x * bpp / 8 + y * size_line] = val->b;
	image[x * bpp / 8 + 1 + y * size_line] = val->g;
	image[x * bpp / 8 + 2 + y * size_line] = val->r;
}
