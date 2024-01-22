/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:58:08 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/22 18:12:52 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
bool	ft_solvemap(char **map, t_design *design)
{
	print_map(map);
	if (design->yc < design->yp && design->xc < design->xp)
	{
		while (design->yc < design->yp)
		{
			if (design->yp - 1 != '1' || design->yp -1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->yp--;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}
			if (design->xp - 1 != '1' || design->xp -1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->xp--;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}
			if (design->xp + 1 != '1' || design->xp +1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->xp++;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}
			if (design->yp + 1 != '1' || design->yp +1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->yp++;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}	
		}
		while (design->xc < design->xp)
		{
			if (design->xp - 1 != '1' || design->xp -1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->xp--;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}	
			if (design->yp - 1 != '1' || design->yp -1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->yp--;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}	
			if (design->yp + 1 != '1' || design->yp +1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->yp++;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}	
			if (design->xp + 1 != '1' || design->xp +1 != 'F')
			{
				map[design->yp][design->xp] = 'F';
				design->xp++;
				map[design->yp][design->xp] = 'P';
				print_map(map);
			}	
		}
	}
	return (true);
}*/
