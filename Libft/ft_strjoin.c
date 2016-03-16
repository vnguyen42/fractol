/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:58:39 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:15:09 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strlen1(const char *mot)
{
	size_t a;

	a = 0;
	if (mot != NULL)
	{
		while (mot[a])
			a++;
	}
	return (a);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		a;
	int		b;

	b = 0;
	a = ft_strlen1(s1) + ft_strlen1(s2);
	tab = (char*)malloc(sizeof(char) * a);
	if (tab == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		tab[b] = s1[a];
		a++;
		b++;
	}
	a = 0;
	while (s2[a])
	{
		tab[b] = s2[a];
		a++;
		b++;
	}
	tab[b] = '\0';
	return (char*)(tab);
}
