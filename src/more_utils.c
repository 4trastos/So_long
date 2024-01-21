/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:28:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/21 19:50:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_playlines(char **map)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (map[y][x + 1] != '\0')
			x++;
		y++;
	}
	return (y - 2);
}

size_t	ft_countboxes(char **map)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y == 1)
	{
		x = 1;
		while (map[y][x + 1] != '\0')
			x++;
		y--;
	}
	return (x - 1);

}

bool	ft_singleline(char **map, size_t boxes)
{
	size_t	y;
	size_t	x;
	int		e;
	int		c;

	e = 0;
	c = 0;
	y = 1;
	while (map[y + 1] != NULL)
	{
		x = 1;
		while (map[y][x + 1] != '\0')
		{
			if (map[y][x] == 'E')
				e = 1;
			if (map[y][x] == 'C')
				c = 1;
			if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'P')
			{
				if (map[y][x + 1] == '1' && map[y][x - 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1' && (c == 0 || e == 0))
					return (false);
			}
			if (map[y][x] == '1' && x != boxes)
			{
				if (map[y][x] == '1' && map[y][x + 1] != '1')
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	ft_multiplelines(char **map, size_t play_lines, size_t boxes) // Esto no está probado ni terminado
{
	size_t	y;
	size_t	x;
	size_t borrar;

	y = 1;
	borrar = play_lines;
	while (map[y + 1] != NULL)
	{
		x = 1;
		while (map[y][x + 1] != '\0')
		{
			if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'P')
			{
				if (map[y][x + 1] == '1' && map[y][x - 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
					return (false);
			}
			if (map[y][x] == '1' && x != boxes)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
