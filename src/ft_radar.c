/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:57:45 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/28 16:31:12 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(t_design *design)
{
	if (design->yp + UP != '1' || design->yp + UP != 'Z')
	{
		if (design->yp + UP == 'E' || design->yp + UP == 'C')
			 return (1);
		else if (design->yp == '0')
			return (2);
		else if (design->yp == 'F')
			return (3);
		else if (design->yp == 'M')
			return (4);
		else
			return (-1);
	}
	else
		return (-1);
}

int	ft_down(t_design *design)
{
	if (design->yp + DOWN != '1' || design->yp + DOWN != 'Z')
	{
		if (design->yp + DOWN == 'E' || design->yp + DOWN == 'C')
			return (1);
		else if (design->yp == '0')
			return (2);
		else if (design->yp == 'F')
			return (3);
		else if (design->yp == 'M')
			return (4);
		else
			return (-1);
	}
	else
		return (-1);
}

int	ft_right(t_design *design)
{
	if (design->xp + RIGHT != '1' || design->xp + RIGHT != 'Z')
	{
		if (design->xp + RIGHT == 'E' || design->xp + RIGHT == 'C')
			return (1);
		else if (design->xp == '0')
			return (2);
		else if (design->xp == 'F')
			return (3);
		else if (design->xp == 'M')
			return (4);
		else
			return (-1);
	}
	else
		return (-1);
}

int	ft_left(t_design *design)
{
	if (design->xp + LEFT != '1' || design->xp + LEFT != 'Z')
	{
		if (design->xp + LEFT == 'E' || design->xp + LEFT == 'C')
			return (1);
		else if (design->xp == '0')
			return (2);
		else if (design->xp == 'F')
			return (3);
		else if (design->xp == 'M')
			return (4);
		else
			return (-1);
	}
	else
		return (-1);
}

char	ft_return_char(char **map, t_design *design)
{
	ft_awards(map, design);
	if (map[design->yp][design->xp] == '0' || map[design->yp][design->xp] == 'P')
		return ('F');
	else if (map[design->yp][design->xp] == 'F')
		return ('M');
	else
		return ('Z');
}
