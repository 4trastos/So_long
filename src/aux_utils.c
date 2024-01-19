/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:13:01 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/19 23:29:26 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_getX(char **map)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while(map[y][x] != '\0')
		x++;
	return (x);
}

int	ft_getY(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
//	printf("Linea: %i\n", i);
	return (i);
}
/*
bool	ft_getY(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if  (map[i + 1] == '\0')
			return (true);
	}
	return (false);
}*/
