/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:31:45 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/17 17:25:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *msg, char **map)
{
	if (map)
		free (map);
	int	i;

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
	if (line)
		free (line);
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit (0);
}
