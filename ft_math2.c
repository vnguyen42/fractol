/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:37:36 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/17 12:02:17 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <math.h>
#include <stdlib.h>

t_double	nsdouble(double a, double b)
{
	t_double new;

	new.x = a;
	new.y = b;
	return (new);
}
