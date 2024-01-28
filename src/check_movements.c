/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:13:40 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/28 16:32:30 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_canmove(char **map, t_design *design, t_move *move)
{
	move->right = (map[design->yp][design->xp + RIGHT] == '1' || map[design->yp][design->xp + RIGHT] == 'Z');
	move->left = (map[design->yp][design->xp + LEFT] == '1' || map[design->yp][design->xp + LEFT] == 'Z');
	move->up = (map[design->yp + UP][design->xp] == '1' || map[design->yp + UP][design->xp] == 'Z');
	move->down = (map[design->yp + DOWN][design->xp] == '1' || map[design->yp + DOWN][design->xp] == 'Z');
	if (move->right && move->left && move->up && move->down)
		return (false);
	else
		return (true);
}

bool	dead_end(char **map, t_design *design, t_move *move)
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
		return (true);
	}
	else
		return (false);
}

void	ft_awards(char **map, t_design *design)
{
	if (map[design->yp][design->xp] == 'C')
	{
		map[design->yp][design->xp] = 'P';
		design->collect = design->collect - 1;
		if (design->collect != 0 || design->exit != 0)
			reset_road(map);
	}
	if (map[design->yp][design->xp] == 'E')
	{
		map[design->yp][design->xp] = 'P';
		design->exit = 0;
		if (design->collect != 0)
			reset_road(map);
	}
}


void	ft_motion(char **map, t_design *design)
{
	if (map[design->yp][design->xp] == '0')
		map[design->yp][design->xp] = 'F';
	else if (map[design->yp][design->xp] == 'F')
		map[design->yp][design->xp] = 'M';
	else if (map[design->yp][design->xp] == 'M')
		map[design->yp][design->xp] = 'Z';

}

void	to_walk(char **map, t_design *design, t_radar *radar)
{
	radar->up = (ft_up(design));
	radar->down = (ft_down(design));
	radar->right = (ft_right(design));
	radar->left = (ft_left(design));
	if (radar->up <= radar->down && radar->up <= radar->right && radar->up <= radar->left)
	{
		map[design->yp][design->xp] = ft_return_char(map, design);
		design->yp = design->yp + UP;
    }
	else if (radar->right <= radar->down && radar->right <= radar->left)
	{
        map[design->yp][design->xp] = ft_return_char(map, design);
		design->yp = design->yp + DOWN;

    }
	else if (radar->down <= radar->left)
	{
		map[design->yp][design->xp] = ft_return_char(map, design);
		design->xp = design->xp + RIGHT;
    }
	else
    {
		map[design->yp][design->xp] = ft_return_char(map, design);
		design->xp = design->xp + LEFT;
	}
}
