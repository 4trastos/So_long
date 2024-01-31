/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:43:19 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/31 13:59:55 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_road(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'F' || map[y][x] == 'M' || map[y][x] == 'Z')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	ft_deadend(char **map, t_design *design, t_move *move)
{
	int		i;

	i = 0;
	if (move->right == (map[design->yp][design->xp + RIGHT] == '1'))
		i++;
	if (move->left == (map[design->yp][design->xp + LEFT] == '1'))
		i++;
	if (move->up == (map[design->yp + UP][design->xp] == '1'))
		i++;
	if (move->down == (map[design->yp + DOWN][design->xp] == '1'))
		i++;
	if (i == 3)
	{
		map[design->yp][design->xp] = '1';
		design->xp -= !move->right;
		design->xp += !move->left;
		design->yp -= !move->up;
		design->yp += !move->down;
	}
}
