/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:00 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 14:51:21 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_solvemap(char **map, t_design *design)
{
	t_move	*move;
	t_radar	*radar;

	radar = ft_new_radar();
	move = ft_new_move();
	while (ft_canmove(map, design, move) && (design->exit != 0
			|| design->collect != 0))
		to_walk(map, design, radar);
	free(move);
	free(radar);
	if (design->collect == 0 && design->exit == 0)
		return (true);
	else
		return (false);
}
