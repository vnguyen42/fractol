/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:37:36 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 10:41:31 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <math.h>
#include <stdlib.h>

t_double	nsdouble(double a, double b)
{
	t_double new;

	new.x = malloc(sizeof(double));
	new.y = malloc(sizeof(double));
	*new.x = a;
	*new.y = b;
	return (new);
}
