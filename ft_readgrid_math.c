/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid_math.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:10:56 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/15 16:13:36 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	number_of_numbers(char *line)
{
	int i;
	int j;
	int number_of_numbers;

	i = 0;
	number_of_numbers = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i + j] >= '0' && line[i + j] <= '9')
			j++;
		i += j;
		if (j > 0)
			number_of_numbers++;
		i++;
	}
	return (number_of_numbers);
}
