/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/03 14:15:19 by davgalle         ###   ########.fr       */
=======
/*   Updated: 2024/02/01 18:16:13 by nicgonza         ###   ########.fr       */
>>>>>>> 57c2c9a7ee7df2cc13b8b66fd7877d91d15a80b6
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

<<<<<<< HEAD
char	**ft_matrixdup(char **map, t_design *design)
=======
char	**ft_matrixdup(char **map)
>>>>>>> 57c2c9a7ee7df2cc13b8b66fd7877d91d15a80b6
{
	char	**copy;
	size_t	y;
	size_t	x;

<<<<<<< HEAD
	y = design->rows;
	x = design->columns;
=======
	y = ft_playlines(map) + 2;
	x = ft_countboxes(map) + 3;
>>>>>>> 57c2c9a7ee7df2cc13b8b66fd7877d91d15a80b6
	copy = (char **)malloc(x * y);
	if (!copy)
		return (NULL);
	copy = ft_matrix_dup_aux(map, copy, x);
	return (copy);
}
