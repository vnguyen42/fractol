/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/16 15:31:13 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_fdf.h"
#include "read_grid.h"
#include "get_next_line.h"

t_point	get_file_dimensions(char *filepath)
{
	int		file;
	char	*buf;
	int		line_length;
	t_point	dimensions;
	int		i;

	line_length = 0;
	dimensions.x = 0;
	dimensions.y = 0;
	file = open(filepath, O_RDONLY);
	while (get_next_line(file, &buf) > 0)
	{
		if (number_of_numbers(buf) > dimensions.x)
			dimensions.x = number_of_numbers(buf);
		dimensions.y++;
		i = 0;
	}
	return (dimensions);
}

int		**intnew(t_point dimensions)
{
	int **tab;
	int i;

	tab = NULL;
	i = 0;
	tab = (int**)malloc(sizeof(int*) * dimensions.y + 10);
	while (i <= dimensions.y)
	{
		tab[i] = (int*)malloc(sizeof(int) * dimensions.x + 10);
		i++;
	}
	return (tab);
}

int		get_next_number(char *line, int *num)
{
	int i;
	int j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && line[i - 1] != '\n')
	{
		j = 0;
		while ((line[i + j] >= '0' && line[i + j] <= '9')
				|| line[i + j] == '-')
			j++;
		if (j > 0)
		{
			*num = ft_atoi(ft_strsub(line, i, j));
			if (ft_strlen(line) == 1)
				return (j - 1);
			else
				return (j);
		}
		i += j;
		i++;
	}
	*num = -42;
	return (-42);
}

int		**get_tab_from_file(char *filepath)
{
	t_point	i;
	t_point	j;
	int		file;
	char	*buf;
	int		**tab;

	i.y = 0;
	file = open(filepath, O_RDONLY);
	tab = intnew(get_file_dimensions(filepath));
	while (get_next_line(file, &buf) > 0)
	{
		i.x = 0;
		j.x = 0;
		j.y = 0;
		while (j.x != -42)
		{
			j.x = get_next_number(&buf[j.y], &tab[i.y][i.x]);
			j.y += j.x + 1;
			i.x++;
		}
		i.y++;
	}
	tab[i.y] = 0;
	return (tab);
}

int		**read_grid(char *filepath)
{
	int	file;
	int	**int_tab;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (NULL);
	int_tab = get_tab_from_file(filepath);
	close(file);
	return (int_tab);
}
