/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 10:40:53 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(int argc, char **argv, t_design *design)
{
	int			fd;
	t_design	*aux;

	aux = design;
	if (argc != 2)
		ft_error_msg("Invalid number of arguments!", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map not found!", NULL);
	if (ft_strnrcmp(argv[1], ".ber", 4))
		ft_error_msg("The file is invalid, use a .ber file!", NULL);
	printf("Listo para crear el mapa \n");
	return (13);
//	return (ft_check_map(fd, design));
}

int	main(int argc, char **argv)
{
//	char		**map;
	int	map;
	t_design	design;

	if (argc == 1)
	{
		write (1, "Insert Coin :)", 14);
		return (1);
	}
	map = ft_check_arg(argc, argv, &design);
	printf("mapa creado, listo para iniciar el juego: %i\n", map);
//	ft_init_game(map, design);
	return (0);
}
