/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:00 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/28 12:39:34 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ***   los movimientos son los siguientes: > ^ < v   *** */

bool	ft_solvemap(char **map, t_design *design)
{
	t_move	*move;
	t_radar	*radar;

	radar = ft_new__move();
	move = ft_new_move();
	while (ft_canmove(map, design, move) && (design->exit != 0 || design->collect != 0)) //Mientras que se pueda mover y haya C o E//
	{
		while (dead_end(map, design, move)) //Si entra está en un callejón sin salida pone un muro y retrocede/
		{
			ft_awards(map, design); //Mira si en la posición que en la que se ha movido hay C o E.
			ft_motion(map, design); //Mira que hay en la posición si NO ha encontrado C o E..
		}
		to_walk(map, design, radar); //Se mueve buscando la prohibición menor. 0 > F > M > Z.)
	}
	free(move);
	if (design->collect == 0 && design->exit == 0)
		return (true);
	else
		return (false);
}
