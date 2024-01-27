/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/27 18:18:17 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_matrixdup(char **map)
{
	char	**copy;
	size_t	y;
	size_t	x;
	size_t	i;

	y = ft_playlines(map) + 2;
	x = ft_countboxes(map) + 3;
	copy = (char **)malloc(x * y);
	if (!copy)
		return (NULL);
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

char	**ft_reload(char **map, t_design *design)
{
	size_t	y;
	size_t	x;

	y = 0;
	printf("A encontrado una 'C'\n");
	printf("Entra a actualizar el mapa\n");
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
				design->xc = x;
			}
			x++;
		}
		y++;
	}
	return (map);
}