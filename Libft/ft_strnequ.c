/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:48:19 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/08 15:50:22 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (a < n)
		{
			if (s1[a] == s2[b])
				b++;
			a++;
		}
		if (a == b)
			return (1);
	}
	return (0);
}
