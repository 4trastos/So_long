/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 22:08:01 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	printf("Entra a printear mapa\n");
   	int i;
	
	i = 0;
	while (map[i] != NULL)
	{
		printf("Dentro del while\n");
		printf("Cadena %d: %s\n", i, map[i]);
		printf("%s\n", map[i]);
		i++;
	}
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

char	**ft_check_arg(int argc, char **argv, t_design *design)
{
	int			fd;
	t_design	*aux;

	aux = design;
	if (argc != 2)
		ft_error_msg("Invalid number of arguments!", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file!");
	   	exit(EXIT_FAILURE);
	}
	if (ft_strnrcmp(argv[1], ".ber", 4))
		ft_error_msg("The file is invalid, use a .ber file!", NULL);
	return (ft_check_map(fd, design));
}

int	main(int argc, char **argv)
{	
	atexit(ft_leaks);
	char		**map;
	t_design	design;

	if (argc == 1)
		ft_error_msg("You have to upload a file to play!", NULL);
	map = ft_check_arg(argc, argv, &design);
	printf("Este el mapa creado: \n");
	print_map(map); //NO PRINTA PORQUE NO LOGRO GUARDAR BIEN EL MAPA.
//	ft_init_game(map, design);
	return (0);
}
