/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 14:27:59 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_check_map(int fd, t_design *design)
{
	char *map_str;
	char **map;
	t_error	map_error;

	map_str = NULL;
	map = NULL;
	map_error = ft_error_map();
	*design = ft_new_design();
	ft_read_design(fd, &map_error, design, &map_str);
}

bool	ft_check_dimension(char **map)
{
	int x;
	int	y;
	int	z;

	z = ft_strlen(map[0]);
	y = 0;
	while (map[y] != '\0')
		y++;
	if (y < 5)
		return (false);
	y = 0;
	while (map[y] != '\0')
	{
		if (map[y] == ' ')
			return (false);
		x = 0;
		while (map[y][x] != '\n')
			x++;
		if (x < 7)
			return (false);
		if (x != z)
			return (false);
		y++;
	}
	return (true);

}
