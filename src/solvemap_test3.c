/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap_test3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:00 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/27 11:02:34 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_solvemap(char **map, t_design *design)
{
//	printf("Entra el mapa\n");
//	prinf_map(map);
	if (design->collect == 0 && design->exit == 0) //Check de recursividad//
		return (true);
	if (design->collect > 0) //Si hay coleccionables//
	{
		printf("Tiene coleccionables\n");
		if (design->yc == design->yp)
		{
			printf("estan en la misma linea 1:\n");
			if (design->yc == design->yp)//si estan en la misma linea//
			{
				printf("Esta en la misma linea 2:\n");
				if (design->xc < design->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							design->collect = design->collect -1;
							printf("Ha encontrado un C\n");
							ft_solvemap(ft_reload(map, design), design);
						}
							map[design->yp][design->xp] = 'P';
							ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
			}
			else if (design->xc == design->xp) //esta en la misma columna.
			{
				printf("Esta en la misma columna:\n");
				if (design->yc < design->yp)//si está arriba//
				{
					if (design->yp - 1 != '1' || design->yp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'C')
						{
							map[design->yp][design->xp] = 'P';
							printf("Ha encontrado un C\n");
							design->collect = design->collect -1;
							ft_solvemap(ft_reload(map, design), design);
						}
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
		printf("NO Tiene coleccionables\n");
		printf("Estra a buscar la salida:\n");
		if (design->ye == design->yp)
		{
			printf("La 'E' está en la misma línea\n");
			if (design->ye == design->yp)//si estan en la misma linea//
			{
				printf("La 'E' Estan en la misma linea:\n");
				if (design->xe < design->xp)
				{
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
				}
				if (design->xe > design->xp)
				{
					printf("La 'E' está a la izquierda línea\n");
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp -1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp + 1 != '1' || design->yp +1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->yp + 1 != '1' || design->yp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp - 1 != '1' || design->xp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);
					}
					if (design->xp + 1 != '1' || design->xp + 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->xp++;
						if (map[design->yp][design->xp] == 'E')
							return (true);
						map[design->yp][design->xp] = 'P';
						ft_solvemap(map, design);

					}
					if (design->yp - 1 != '1' || design->yp - 1 != 'F')
					{
						map[design->yp][design->xp] = 'F';
						design->yp--;
						if (map[design->yp][design->xp] == 'E')
							return (true);
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
