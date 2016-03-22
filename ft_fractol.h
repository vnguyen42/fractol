/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:59:48 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/22 11:02:26 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# define WIN_WIDTH 400
# define WIN_HEIGHT 400
# define JULIA 1
# define MANDELBROT 2
# define OTHER 3
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct		s_line
{
	double x;
	double y;
	double length;
	double addx;
	double addy;
}					t_line;

typedef struct		s_double
{
	double x;
	double y;
}					t_double;

typedef struct		s_fractal
{
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom;
	double	movex;
	double	movey;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		max_iter;
}					t_fractal;

typedef struct		s_point
{
	int x;
	int y;
	int z;
}					t_point;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			r;
	int			g;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			b;
	int			fractale;
	void		*screen;
	float		rotation;
	float		hauteur;
	int			tmp;
	double		zoom;
	double		cim;
	double		cre;
	double		movex;
	double		movey;
	int			max_iter;
	int			color_mode;
	t_point		pos;
	t_fractal	k;
	int			color;
	int			grid_space;
	int			ft_hauteur_animation;
	int			ft_hauteur_animation_going;
	t_point		dimensions;
}					t_env;

int					init_fractol(int fractale);
void				draw_line(t_env *env, t_point a, t_point b);
void				draw_grid(t_env *env, int clear);
t_point				ft_projection(t_env *env, t_point p, float cte);
t_point				ft_rotation(t_env *env, t_point p, float angle);
int					ft_key_handler(int keycode, void *param);
int					ft_int_diff(int a, int b);
void				pixel_to_image(unsigned long color, t_env *val,
		int x, int y);
void				clear_screen(t_env *env);
int					number_of_numbers(char *line);
t_double			*ndouble(double a, double b);
t_double			nsdouble(double a, double b);
void				draw_julia(t_env *env);
unsigned long		create_rgba(int r, int g, int b, int a);
int					ft_positive(int a);
t_fractal			init_julia(t_env *env);
void				draw_julia_color(t_env *env, int max_iter, t_point x,
					int i);
void				ft_hauteur_animation(void *param);
t_point				rt_point(int x, int y);
int					ft_mouse_handler(int keycode, int x, int y, void *param);
void				zoom_in(t_env *env, double xspan, double yspan,
					t_double new);
void				zoom_out(t_env *env, double xspan, double yspan);
int					ft_expose_handler(int x, int y, void *param);
int					for_burningship(t_fractal *k, t_point x);

#endif
