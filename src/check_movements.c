/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:13:40 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/09 17:27:42 by davgalle         ###   ########.fr       */
/*   Updated: 2024/02/01 18:05:25 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_canmove(char **map, t_design *design, t_move *move)
{
	move->right = (map[design->yp][design->xp + RIGHT] == '1'
			|| map[design->yp][design->xp + RIGHT] == 'Z');
	move->left = (map[design->yp][design->xp + LEFT] == '1'
			|| map[design->yp][design->xp + LEFT] == 'Z');
	move->up = (map[design->yp + UP][design->xp] == '1'
			|| map[design->yp + UP][design->xp] == 'Z');
	move->down = (map[design->yp + DOWN][design->xp] == '1'
			|| map[design->yp + DOWN][design->xp] == 'Z');
	if (move->right && move->left && move->up && move->down)
		return (false);
	else
		return (true);
}

static void	t_radar_declaration(char **map, t_design *design, t_radar *radar)
{
	radar->up = (ft_up(map, design));
	radar->down = (ft_down(map, design));
	radar->right = (ft_right(map, design));
	radar->left = (ft_left(map, design));
}

void	to_walk(char **map, t_design *design, t_radar *radar)
{
	t_radar_declaration(map, design, radar);
	if (radar->up <= radar->down && radar->up <= radar->right
		&& radar->up <= radar->left)
	{
		map[design->yp][design->xp] = ft_return_char(map, design);
		design->yp = design->yp + UP;
	}
	else if (radar->down <= radar->up
		&& radar->down <= radar->right && radar->down <= radar->left)
	{
		map[design->yp][design->xp] = ft_return_char(map, design);
		design->yp = design->yp + DOWN;
	}
	else if (radar->right <= radar->up
		&& radar->right <= radar->down && radar->right <= radar->left)
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
