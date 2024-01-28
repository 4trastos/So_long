/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:57:45 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/28 13:32:03 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(char **map, t_design *design, t_radar *radar)
{
	if (design->yp + UP != '1' || design->yp + UP != 'Z')
	{
		if (design->yp + UP == 'E' || design->yp + UP == 'C')
			radar->up = 1;
		else if (design->yp == '0')
			radar->up = 2;
		else if (design->yp == 'F')
			radar->up = 3;
		else if (design->yp == 'M')
			radar->up = 4;
		else
			radar->up = 5;
	}
	else
		radar->up = -1;
}

void	ft_down(char **map, t_design *design, t_radar *radar)
{
	if (design->yp + DOWN != '1' || design->yp + DOWN != 'Z')
	{
		if (design->yp + DOWN == 'E' || design->yp + DOWN == 'C')
			radar->down = 1;
		else if (design->yp == '0')
			radar->down = 2;
		else if (design->yp == 'F')
			radar->down = 3;
		else if (design->yp == 'M')
			radar->down = 4;
		else
			radar->down = 5;
	}
	else
		radar->down = -1;
}

void	ft_right(char **map, t_design *design, t_radar *radar)
{
	if (design->xp + RIGHT != '1' || design->xp + RIGHT != 'Z')
	{
		if (design->xp + RIGHT == 'E' || design->xp + RIGHT == 'C')
			radar->right = 1;
		else if (design->xp == '0')
			radar->right = 2;
		else if (design->xp == 'F')
			radar->right = 3;
		else if (design->xp == 'M')
			radar->right = 4;
		else
			radar->right = 5;
	}
	else
		radar->right = -1;
}

void	ft_left(char **map, t_design *design, t_radar *radar)
{
	if (design->xp + LEFT != '1' || design->xp + LEFT != 'Z')
	{
		if (design->xp + LEFT == 'E' || design->xp + LEFT == 'C')
			radar->left = 1;
		else if (design->xp == '0')
			radar->left = 2;
		else if (design->xp == 'F')
			radar->left = 3;
		else if (design->xp == 'M')
			radar->left = 4;
		else
			radar->left = 5;
	}
	else
		radar->left = -1;
}
