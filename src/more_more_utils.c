/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/09 12:13:25 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_matrix_dup_aux(char **map, char **copy, size_t x)
{
	size_t	y;
	size_t	i;

	y = 0;
	while (map[y] != NULL)
	{
		i = 0;
		copy[y] = (char *)malloc(sizeof(char) * x);
		if (!copy[y])
		{
			while (y > 0)
				free(copy[--y]);
			free(copy);
			return (NULL);
		}
		while (map[y][i] != '\0')
		{
			copy[y][i] = map[y][i];
			i++;
		}
		copy[y][i] = '\0';
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

char	**ft_matrixdup(char **map, t_design *design)
{
	char	**copy;
	size_t	y;
	size_t	x;

	y = design->rows;
	x = design->columns;
	copy = (char **)malloc(x * y);
	if (!copy)
		return (NULL);
	copy = ft_matrix_dup_aux(map, copy, x);
	return (copy);
}

void		load_enemies(char **map, t_design *design)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'W')
			{
				design->yw = y;
				design->xw = x;
			}
			x++;
		}
		y++;
	}
}

void	load_data(char **map, t_design *design)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				design->yp = y;
				design->xp = x;
			}
			if (map[y][x] == 'E')
			{
				design->ye = y;
				design->xe = x;
			}
			x++;
		}
		y++;
	}
}
