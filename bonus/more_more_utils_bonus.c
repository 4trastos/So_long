/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:24 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/20 16:35:01 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemies(char **map, t_design *design)
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
