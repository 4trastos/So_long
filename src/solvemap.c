/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:59 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/22 19:49:28 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "so_long.h"

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
				while (design->xc < design->xp)
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
				while (design->xc > design->xp)
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
			if (design->yc < design->yp)
			{
				while (design->xc < design->xp)
				{

				}
				while (design->xc > design->xp)
				{

				}
				if (design->xc == design->xp) //No sé si será necesario//
				{

				}
			}
			if (design->yc > design->yp)
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
		// Volver a cargar el mapa 	RECURSIVAMENTE hasta que se cumpla el primer if. //
	return (true);
}
