/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:46:00 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:18:37 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		contagebis(char const *s, char c)
{
	int a;
	int b;

	b = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			b++;
			while (s[a] != c && s[a] != '\0')
			{
				a++;
			}
			a--;
		}
		a++;
	}
	return (b);
}

static int		memoire(int a, char c, const char *s)
{
	int index;

	index = 0;
	while (s[a] != c && s[a] != '\0')
	{
		a++;
		index++;
	}
	return (index);
}

static int		contage(int a, char c, const char *s)
{
	int temp;

	temp = a;
	while (s[temp] != c && s[temp] != '\0')
		temp++;
	return (temp);
}

static int		algo(const char *s, char c, char **ss, int x)
{
	int a;
	int index;

	a = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			index = memoire(a, c, s);
			ss[x] = (char*)malloc(sizeof(char) * index + 1);
			index = 0;
			while (a < contage(a, c, s))
			{
				ss[x][index] = s[a];
				index++;
				a++;
			}
			ss[x][index] = '\0';
			x++;
			a--;
		}
		a++;
	}
	return (x);
}

char			**ft_strsplit(char const *s, char c)
{
	int		x;
	char	**ss;

	if (s == NULL)
		return (NULL);
	x = contagebis(s, c);
	ss = (char**)malloc(sizeof(char*) * x + 1);
	if (ss == NULL || s == NULL)
		return (NULL);
	x = 0;
	x = algo(s, c, ss, x);
	ss[x] = 0;
	return (ss);
}
