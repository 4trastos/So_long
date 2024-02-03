/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 18:16:13 by nicgonza         ###   ########.fr       */
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

char	**ft_matrixdup(char **map)
{
	char	**copy;
	size_t	y;
	size_t	x;

	y = ft_playlines(map) + 2;
	x = ft_countboxes(map) + 3;
	copy = (char **)malloc(x * y);
	if (!copy)
		return (NULL);
	copy = ft_matrix_dup_aux(map, copy, x);
	return (copy);
}
