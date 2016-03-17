/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 11:59:11 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "Libft/libft.h"
#include <stdio.h>

void	draw_grid(t_env *env, int clear)
{
	if (clear)
		clear_screen(env);
	draw_julia(env);	
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
