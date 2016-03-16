/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:09:35 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/16 09:27:23 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (s1 != NULL && s2 != NULL)
	{
		ss1 = (unsigned char*)s1;
		ss2 = (unsigned char*)s2;
		while (n > 0)
		{
			if (*ss1 != *ss2)
				return (*ss1 - *ss2);
			n--;
			ss1++;
			ss2++;
		}
	}
	return (0);
}
