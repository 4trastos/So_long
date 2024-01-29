/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/29 18:35:11 by davgalle         ###   ########.fr       */
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
