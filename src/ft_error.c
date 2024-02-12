/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:31:45 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/12 20:03:13 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_error_msg(char *msg, char **map)
{
	int	i;

	if (map)
		free (map);
	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (0);
}

void	ft_error_map(char *msg, char *line)
{
	int	i;

	if (line)
		free (line);
	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (0);
}

void	ft_freemap(char *msg, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (0);
}

void	ft_freedoublemap(char *msg, char **map, char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	ft_freemap(msg, map);
}
