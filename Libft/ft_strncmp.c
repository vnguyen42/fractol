/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:41 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/16 09:41:50 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL && n != 0)
	{
		while (n > 0)
		{
			if (*s1 != *s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
			if (*s1 == '\0')
				return (0);
			if (*s2 == '\0')
				return (0);
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}
