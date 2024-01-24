/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:59 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:14 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
bool	ft_solvemap(char **map, t_design *design)
{
	print_map(map);
	if (design->collect == 0 && design->exit == 0) //Este es el check para que pare la recursividad//
		return (true);
	if (design->collect != 0) //Cuando aún hay coleccionables//
	{
		while (design->yc != design->yp && design->xc != design->xp) //Hasta que se igualan las posiciones Es posible que pete//
		{
			if (design->yc == design->yp) //si estan en la misma linea//
			{
				while (design->xc < design->xp && design->collect != 0)//si está a la derecha//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] = 'C')//Cuando encuentra el coleccionable//
						{
							map[design->yp][design->xp] = 'P';
							design->collect = design->collect -1;
							ft_solvemap(map, design);
						}
						else
							map[design->yp][design->xp] = 'P';
						print_map(map);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] = 'C')//Cuando encuentra el coleccionable//
						{
							map[design->yp][design->xp] = 'P';
							design->collect == -1;
						}
						else
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
				while (design->xc > design->xp && design->collect != 0)//si está a la izquierda//
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
			}
			if (design->xc == design->xp) //si estan en la misma columna//
			{
				while (design->yc < design->yp && design->collect != 0)//si está abajo//
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
				while (design->xc > design->xp && design->collect != 0)//si está arriba//
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
			}
			if (design->yc < design->yp) //si está a la izquierda//
			{
				while (design->xc < design->xp)
				{
					map[desing->xp][desing->yp] = 'F';
					desing->xp--;
					map[desing->xp][desing->yp] = 'P';
				}
				while (design->xc > design->xp)
				{
					map[desing->xp][desing->yp] = 'F';
					desing->xp++;
					map[desing->xp][desing->yp] = 'P';
				}
				if (design->xc == design->xp) //No sé si será necesario//
				{

				}
			}
			if (design->yc > design->yp)//si está a la derecha//
			{
				while (design->xc < design->xp)
				{

				}
				while (design->xc > design->xp)
				{

				}
				if (design->xc == design->xp) // No sé si será necesario//
				{

				}
			}	
		}
		if (design->exit == 1 && design->collect == 0) //Busca la salida//
		{
			while (design->ye != design->yp && design->xe != design->xp)
			{
				if (design->yc == design->yp)
				{
					if (design->xc < design->xp)
					{
						while ()
					}
					if (design->xc > design->xp)
					{

					}
				}
				if (design->yc < design->yp)
				{
					if (design->xc < design->xp)
					{

					}
					if (design->xc > design->xp)
					{

					}
					if (design->xc == design->xp)
					{

					}
				}
				if (design->yc > design->yp)
				{
					if (design->xc < design->xp)
					{

					}
					if (design->xc > design->xp)
					{

					}
					if (design->xc == design->xp)
					{

					}
				}
			}
		}
	}
	if (design->yc == design->yp && design->xc == design->xp)
		ft_solvemap(map, design);// Volver a cargar el mapa 	RECURSIVAMENTE hasta que se cumpla el primer if. //
	return (false);
}*/
