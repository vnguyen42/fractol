/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractales.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:01:35 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 10:41:15 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	draw_julia_iterator(t_double *x, t_double *y,
		t_double *ni, t_double *cacb)
{
	int do_while = 1;

	while (do_while || ((*ni->y < (double)100) && (*ni->x < (double)2)))
	{
		do_while = 0;
		ni->y++;
		*x->y = (*x->x * *x->x) - (*y->y * *y->y) + *cacb->x;
		*y->y = 2 * *y->x * *x->x + *cacb->y;
		*ni->x = sqrt(*x->y * *x->y + *y->y * *y->y);
		*x->x = *x->y;
		*y->x = *y->y;
	}
}

void	draw_julia(t_env *env, double ca, double cb, double zoom)
{
	t_point pos;
	double iterator;
	double norme;
	t_double x, y;

	x = nsdouble(0.0,0.0);
	y = nsdouble(0.0, 0.0);
	pos.x = -(WIN_WIDTH/2);
	while (pos.x < (WIN_WIDTH/2))
	{
		pos.y = -(WIN_HEIGHT/2);
		while (pos.y < (WIN_HEIGHT/2))
		{
			*x.x = pos.x / zoom;
			*y.x = pos.y / zoom;
			iterator = 0;
			draw_julia_iterator(&x, &y, ndouble(&norme, &iterator)
								, ndouble(&ca, &cb));
			(void)(env);
			pos.y++;
		}
		pos.x++;
	}
}
