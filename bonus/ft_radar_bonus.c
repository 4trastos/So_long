/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:57:45 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 14:50:17 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(char **map, t_design *design)
{
	if (map[design->yp + UP][design->xp] != '1'
			|| map[design->yp + UP][design->xp] != 'Z')
	{
		if (map[design->yp + UP][design->xp] == 'E'
			|| map[design->yp + UP][design->xp] == 'C')
			return (1);
		else if (map[design->yp + UP][design->xp] == '0')
			return (2);
		else if (map[design->yp + UP][design->xp] == 'F')
			return (3);
		else if (map[design->yp + UP][design->xp] == 'M')
			return (4);
		else
			return (5);
	}
	else
		return (5);
}

int	ft_down(char **map, t_design *design)
{
	if (map[design->yp + DOWN][design->xp] != '1'
			|| map[design->yp + DOWN][design->xp] != 'Z')
	{
		if (map[design->yp + DOWN][design->xp] == 'E'
			|| map[design->yp + DOWN][design->xp] == 'C')
			return (1);
		else if (map[design->yp + DOWN][design->xp] == '0')
			return (2);
		else if (map[design->yp + DOWN][design->xp] == 'F')
			return (3);
		else if (map[design->yp + DOWN][design->xp] == 'M')
			return (4);
		else
			return (5);
	}
	else
		return (5);
}

int	ft_right(char **map, t_design *design)
{
	if (map[design->yp][design->xp + RIGHT] != '1'
			|| map[design->yp][design->xp + RIGHT] != 'Z')
	{
		if (map[design->yp][design->xp + RIGHT] == 'E'
			|| map[design->yp][design->xp + RIGHT] == 'C')
			return (1);
		else if (map[design->yp][design->xp + RIGHT] == '0')
			return (2);
		else if (map[design->yp][design->xp + RIGHT] == 'F')
			return (3);
		else if (map[design->yp][design->xp + RIGHT] == 'M')
			return (4);
		else
			return (5);
	}
	else
		return (5);
}

int	ft_left(char **map, t_design *design)
{
	if (map[design->yp][design->xp + LEFT] != '1'
			|| map[design->yp][design->xp + LEFT] != 'Z')
	{
		if (map[design->yp][design->xp + LEFT] == 'E'
			|| map[design->yp][design->xp + LEFT] == 'C')
			return (1);
		else if (map[design->yp][design->xp + LEFT] == '0')
			return (2);
		else if (map[design->yp][design->xp + LEFT] == 'F')
			return (3);
		else if (map[design->yp][design->xp + LEFT] == 'M')
			return (4);
		else
			return (5);
	}
	else
		return (5);
}

char	ft_return_char(char **map, t_design *design)
{
	if (map[design->yp][design->xp] == 'C')
	{
		design->collect = design->collect - 1;
		if (design->collect > 0 || design->exit > 0)
			reset_road(map);
		return ('0');
	}
	else if (map[design->yp][design->xp] == 'E')
	{
		design->exit = design->exit - 1;
		if (design->collect > 0)
			reset_road(map);
		return ('0');
	}
	else if (map[design->yp][design->xp] == '0'
			|| map[design->yp][design->xp] == 'P')
		return ('F');
	else if (map[design->yp][design->xp] == 'F')
		return ('M');
	else
		return ('Z');
}
