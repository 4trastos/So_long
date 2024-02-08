/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:28:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 13:11:15 by davgalle         ###   ########.fr       */
/*   Updated: 2024/02/01 18:33:16 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_ifpow_aux(char **map, t_design *design, size_t x, size_t y)
{
	if (map[y][x] == 'P')
	{
		if (map[y][x + 1] == '1' && map[y][x - 1] == '1'
				&& map[y + 1][x] == '1' && map[y - 1][x] == '1')
			return (false);
		design->yp = y;
		design->xp = x;
	}
	if (map[y][x] == 'E')
	{
		if (map[y][x + 1] == '1' && map[y][x - 1] == '1'
				&& map[y + 1][x] == '1' && map[y - 1][x] == '1')
			return (false);
		design->ye = y;
		design->xe = x;
	}
	if (map[y][x] == 'C')
	{
		if (map[y][x + 1] == '1' && map[y][x - 1] == '1'
				&& map[y + 1][x] == '1' && map[y - 1][x] == '1')
			return (false);
		design->yc = y;
		design->xc = x;
	}
	return (true);
}

bool	ft_multiplelines(char **map, t_design *design)
{
	if (!ft_ifpow(map, design))
		return (false);
	if (!ft_solvemap(map, design))
		return (false);
	return (true);
}

bool	ft_ifpow(char **map, t_design *design)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (!ft_ifpow_aux(map, design, x, y))
				return (false);
			else
				x++;
		}
		y++;
	}
	return (true);
}
