/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:07:03 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/16 09:26:46 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ss;
	size_t				a;
	unsigned char		stop;

	a = 0;
	stop = (unsigned char)c;
	ss = (unsigned char*)s;
	while (n--)
	{
		if (ss[a] == stop)
			return (ss + a);
		a++;
	}
	return (NULL);
}
