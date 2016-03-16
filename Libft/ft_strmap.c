/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:19:48 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:15:29 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		a;

	a = 0;
	if (s != NULL && f != NULL)
	{
		s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (s2 == NULL)
			return (NULL);
		while (s[a])
		{
			s2[a] = f(s[a]);
			a++;
		}
		s2[a] = '\0';
		return (s2);
	}
	return (0);
}
