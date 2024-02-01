/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 18:07:38 by nicgonza         ###   ########.fr       */
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
	char		**map;
	t_design	*design;

	atexit(ft_leaks);
	map = NULL;
	design = ft_new_design();
	if (argc == 1)
		ft_error_msg("You have to upload a file to play!", NULL);
	map = ft_check_arg(argc, argv, design, map);
	ft_window(map, design);
//	ft_init_game(map, design);
	free(design);
	return (0);
}
