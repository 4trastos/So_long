/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:13:40 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/27 23:06:30 by davgalle         ###   ########.fr       */
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
	if (move->right = (map[design->yp][design->xp + RIGHT] == '1'))
		i++;
	if (move->left = (map[design->yp][design->xp + LEFT] == '1'))
		i++;
	if (move->up = (map[design->yp + UP][design->xp] == '1'))
		i++;
	if (move->down = (map[design->yp + DOWN][design->xp] == '1'))
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

void	to_walk(char **map, t_design *design) // cuando la primera opción no es 0 y  no es Z, por lo que se podría mover,  debe de moverse siempre hacia la menor prohibición (buscar < M).
{
	if (design->xp + LEFT != '1' || design->xp + LEFT != 'Z') //Busca a su derecha!//
	{
		if (design->xp + LEFT == 'C' || design->xp + LEFT == 'E')
		{
			design->xp++;
			ft_awards(map, design);
		}
		else if (design->xp + LEFT == '0' || design->xp + LEFT == 'F' || design->xp + LEFT == 'M')
		{
			if (design->xp + LEFT == '0')
				map[design->yp][design->xp] = 'F';
			else if (design->xp + LEFT == 'F')
				map[design->yp][design->xp] = 'M';
			else
				map[design->yp][design->xp] = 'Z';
			design->xp++;
		}
	}
	if (design->yp + UP != '1' || design->yp + UP != 'Z') //Busca arriba//
	{
		if (design->yp + UP == 'C' || design->yp + UP == 'E')
		{
			design->yp--;
			ft_awards(map, design);
		}
		else if (design->yp + UP == '0' || design->yp + UP == 'F' || design->yp + UP == 'M')
		{
			if (design->yp + UP == '0')
				map[design->yp][design->xp] = 'F';
			else if (design->xp + UP == 'F')
				map[design->yp][design->xp] = 'M';
			else
				map[design->yp][design->xp] = 'Z';
			design->yp--;
		}
	}
	if (design->xp + RIGHT != '1' || design->xp + RIGHT != 'Z') //Busca a su izquierda//
	{
		if (design->xp + RIGHT == 'C' || design->xp + RIGHT == 'E')
		{
			design->xp--;
			ft_awards(map, design);
		}
		else if (design->xp + RIGHT == '0' || design->xp + RIGHT == 'F' || design->xp + RIGHT == 'M')
		{
			if (design->xp + RIGHT == '0')
				map[design->yp][design->xp] = 'F';
			else if (design->xp + RIGHT == 'F')
				map[design->yp][design->xp] = 'M';
			else
				map[design->yp][design->xp] = 'Z';
			design->xp--;
		}
	}
}
