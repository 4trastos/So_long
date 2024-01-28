/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:00 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/28 16:54:58 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ***   los movimientos son los siguientes: ^ > v <   *** */

bool	ft_solvemap(char **map, t_design *design)
{
	t_move	*move;
	t_radar	*radar;

	radar = ft_new_radar();
	move = ft_new_move();
	print_map(map);
	while (ft_canmove(map, design, move) && (design->exit != 0 || design->collect != 0))
	{
		while (dead_end(map, design, move)) //Si entra está en un callejón sin salida pone un muro y retrocede/
		{
			ft_awards(map, design);
			ft_motion(map, design);
		}
		to_walk(map, design, radar);
	}
	free(move);
	if (design->collect == 0 && design->exit == 0)
		return (true);
	else
		return (false);
}
