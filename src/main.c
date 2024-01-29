/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/29 18:30:27 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	printf("Map:\n");
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

char	**ft_check_arg(int argc, char **argv, t_design *design, char **map)
{
	int			fd;

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
	return (ft_check_map(fd, design, map));
}

int	main(int argc, char **argv)
{	
	atexit(ft_leaks);
	char		**map;
	t_design	*design;

	map = NULL;
	design = ft_new_design();
	if (argc == 1)
		ft_error_msg("You have to upload a file to play!", NULL);
	map = ft_check_arg(argc, argv, design, map);
	print_map(map);
	free(design);
	ft_free_map(map);
//	ft_init_game(map, design);
	return (0);
}
