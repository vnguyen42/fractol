/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:22:47 by vnguyen            #+#    #+#             */
/*   Updated: 2015/12/11 17:10:54 by vnguyen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*zero(char *str)
{
	str = malloc(sizeof(char) * 1 + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	return (char *)(str);
}

static int		ft_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	char	*verife(void)
{
	char *min;

	min = malloc(sizeof(char) * 12);
	if (min == NULL)
		return (NULL);
	min[0] = '-';
	min[1] = '2';
	min[2] = '1';
	min[3] = '4';
	min[4] = '7';
	min[5] = '4';
	min[6] = '8';
	min[7] = '3';
	min[8] = '6';
	min[9] = '4';
	min[10] = '8';
	min[11] = '\0';
	return (char*)(min);
}

static char		*ft_transformeur(char *str, int count, int n, int signe)
{
	if (n < 0)
	{
		signe = 1;
		n = n * -1;
	}
	str[count] = '\0';
	while (count-- >= 0)
	{
		str[count] = n % 10 + 48;
		n = n / 10;
	}
	if (signe == 1)
		str[0] = '-';
	return (char *)(str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		signe;

	str = NULL;
	signe = 0;
	if (n == -2147483648)
		return (verife());
	if (n == 0 || n < -2147483647 || n > 2147483647)
		return (char*)(zero(str));
	count = ft_count(n);
	str = (char*)malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	return (char*)(ft_transformeur(str, count, n, signe));
}
