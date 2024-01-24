/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:00 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/24 17:31:58 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_solvemap(char **map. t_design *design)
{
	if (design->collect == 0 && design->exit == 0) //Check de recursividad//
		return (true);
	if (design->collect != 0) //Si hay coleccionables//
	{
		if (design->yc != design->yp && design->xc != design->xp)
		{
			if (design->yc == design->yp)//si estan en la misma linea//
			{
				if (desing->xc < desing->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (desing->xc > desing->xp)
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
			}
			if else (design->xc == design->xp)
			{
				if (design->yc < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';	
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->yc > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->y++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';	
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}

			}
			else 
			{
				if (desing->xc < desing->xp)//si está a al izquierda//
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->yc < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';	
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (desing->xc > desing->xp)//Si está a la derecha//
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->yc > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->y++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';	
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
			}
		}
		else
		{
		design->collect = design->collect - 1;
		ft_solvemap(map, desing);
		}
	}
	else //Busca la salida//
	{
		if (design->ye != design->yp && design->xe != design->xp)
		{
			if (design->ye == design->yp)//si estan en la misma linea//
			{
				if (desing->xe < desing->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (desing->xe > desing->xp)
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
			}
			if else (design->xe == design->xp)
			{
				if (design->ye < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->ye > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->y++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}

			}
			else
			{
				if (desing->xe < desing->xp)//si está a al izquierda//
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->ye < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (desing->xe > desing->xp)//Si está a la derecha//
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
				if (design->ye > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->y++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, desing);
					}
				}
			}
		}
		else 
			return (true);
	}
	return (false);
}

