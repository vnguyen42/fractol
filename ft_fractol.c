/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:18:32 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/20 19:44:12 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_fractol.h"
#include <unistd.h>

int		ft_translucid(void *param)
{
	t_env *env;

	env = param;
	ft_hauteur_animation(env);
	draw_grid(env, 1);
	return (1);
}

void	init_env_vars(t_env *env)
{
	env->rotation = 101;
	env->color = 0x00ace6;
	env->color = 19000;
	env->pos.x = 0;
	env->pos.y = 0;
	env->hauteur = 1.0;
	env->grid_space = 30;
	env->ft_hauteur_animation = 0;
	env->ft_hauteur_animation_going = 0;
	env->zoom = 1.0;
	env->max_iter = 90;
	env->movex = 0;
	env->movey = 0;
	env->cre = -0.4;
	env->cim = 0.6;
	env->cre = -1.417022285618;
	env->cim = 0.0099534;
	env->color_mode = 1;
	env->fractale = JULIA;
	env->color = 0;
}

int		init_fractol(int fractale)
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_do_key_autorepeaton(&env);
	init_env_vars(&env);
	mlx_loop_hook(env.mlx, ft_translucid, &env);
	env.fractale = fractale;
	draw_grid(&env, 1);
	mlx_key_hook(env.win, ft_key_handler, &env);
	mlx_loop(env.mlx);
	return (1);
}
