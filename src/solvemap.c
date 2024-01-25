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

bool	ft_solvemap(char **map, t_design *design)
{
	if (design->collect == 0 && design->exit == 0) //Check de recursividad//
		return (true);
	if (design->collect != 0) //Si hay coleccionables//
	{
		if (design->yc != design->yp && design->xc != design->xp)
		{
			if (design->yc == design->yp)//si estan en la misma linea//
			{
				if (design->xc < design->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->xc > design->xp)
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
			}
			else if (design->xc == design->xp)
			{
				if (design->yc < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->yc > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}

			}
			else
			{
				if (design->xc < design->xp)//si está a al izquierda//
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->yc < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->xc > design->xp)//Si está a la derecha//
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->yc > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
			}
		}
		else
		{
		design->collect = design->collect - 1;
		ft_solvemap(map, design);
		}
	}
	else //Busca la salida//
	{
		if (design->ye != design->yp && design->xe != design->xp)
		{
			if (design->ye == design->yp)//si estan en la misma linea//
			{
				if (design->xe < design->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->xe > design->xp)
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
			}
			else if (design->xe == design->xp)
			{
				if (design->ye < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->ye > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}

			}
			else
			{
				if (design->xe < design->xp)//si está a al izquierda//
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->ye < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->xe > design->xp)//Si está a la derecha//
				{
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->ye > design->yp)//Si está abajo//
				{
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
			}
		}
		else
			return (true);
	}
	return (false);
}
