/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:13:01 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/25 17:56:48 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_getY(char **map, int c)
{
	int	i;
	int result;

	i = 0;
	while (map[i] != NULL)
		i++;
	result = i -1;
	if (result == c)
		return (true);
	else
		return (false);
}

bool	ft_getX(char **map, int c)
{
	int x;
	int y;
	int result;

	y = 0;
	x = 0;
	while(map[y][x] != '\0')
		x++;
	result = x -1;
	if (result == c)
		return (true);
	else
		return (false);
}

bool	ft_middle_map(char *str, t_design *design)
{
	int	i;
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			x++;
		if (str[i] == '0')
			y++;
		if (str[i] == 'E')
			z++;
		i++;
	}
	design->wall = x;
	design->space = y;
	design->exit = z;
	if (z != 1)
		return (false);
	else
		return (true);
}

bool	ft_restmap(char *str, t_design *design)
{
	int	i;
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			x++;
		if (str[i] == 'W')
			y++;
		if (str[i] == 'C')
			z++;
		i++;
	}
	design->player = x;
	design->enemys = y;
	design->collect = z;
	if (x != 1 || z < 1)
		return (false);
	else
		return (true);
}

bool	ft_completemap(char *str, t_design *design)
{
	if (ft_middle_map(str, design) && ft_restmap(str, design))
		return (true);
	else
		return (false);
}
