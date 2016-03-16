/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:21:33 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/16 15:36:18 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "read_grid.h"

typedef struct		s_line
{
	double x;
	double y;
	double length;
	double addx;
	double addy;
}					t_line;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		r;
	int		g;
	int		b;
	void	*screen;
	float	rotation;
	float	hauteur;
	int		**tab;
	int		tmp;
	t_point	pos;
	int		color;
	int		grid_space;
	int		ft_hauteur_animation;
	int		ft_hauteur_animation_going;
	t_point dimensions;
}					t_env;

int					init_fdf();
void				draw_line(t_env *env, t_point a, t_point b);
void				draw_grid(t_env *env, int clear);
t_point				ft_projection(t_env *env, t_point p, float cte);
t_point				ft_rotation(t_env *env, t_point p, float angle);
int					ft_key_handler(int keycode, void *param);
int					ft_int_diff(int a, int b);
void				pixel_to_image(unsigned long color, t_env *val,
					int x, int y);
void				ft_hauteur_animation(void *param);
void				clear_screen(t_env *env);
int					number_of_numbers(char *line);

#endif
