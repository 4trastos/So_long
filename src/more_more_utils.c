/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/25 16:19:48 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_matrixdup(char **map)
{
	char	**copy;
	size_t	y;
	size_t	x;

	y = ft_playlines(map) + 2;
	x = ft_countboxes(map) + 1;
	copy = (char *)malloc(sizeof(char *) * y);
	if (!copy)
		return (NULL);
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		copy[y] = (char *)malloc(sizeof(char *) x);
		if (!copy[y])
		{
			while (y > 0)
				free(copy[--y]);
			free(copy);
			return (NULL);
		}
		while (map[y][x] != '\0')
		{
			copy[y][x] = map[y][x];
			x++;
		}
		copy[y][x] = '\0';
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

char	**ft_reload(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'F')
				map[y][x] = '0';
			if (map[y][x] == 'C')
			{
				design->yc = y;
				design->xc = c;
			}
			x++;
		}
		y++;
	}
	return (map);
}
