/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 14:48:03 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	**ft_check_map(int fd, t_design *design, char **map)
{
	char	*str;
	char	**copy;
	t_error	*error;

	str = NULL;
	copy = NULL;
	error = ft_new_error();
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	str = ft_read_file(fd, error, str, design);
	map = ft_split(str, '\n');
	if (!ft_check_border(map, design))
		ft_freemap("The map must be closed by walls", map);
	copy = ft_matrixdup(map, design);
	if (!ft_feasible_map(copy, design))
		ft_freedoublemap("The map is not feasible", map, copy);
	free(str);
	free(error);
	ft_free_map(copy);
	return (map);
}

bool	ft_check_dimension(char *line, t_error *error, size_t file_size)
{
	int		i;
	size_t	len;

	if (ft_strchr(line, '\n'))
		len = ft_strlen_custom(line);
	else
		len = ft_strlen(line);
	if (len < 6)
		return (false);
	if (len != file_size - 1)
		return (false);
	i = 0;
	while (len > 0)
	{
		if (!is_valid_char(line[i], error))
			return (false);
		i++;
		len--;
	}
	return (true);
}

bool	ft_check_border(char **map, t_design *design)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if ((y == 0 || ft_gety(map, y)) && map[y][x] != '1')
				return (false);
			else if (y != 0)
			{
				if ((x == 0 || ft_getx(map, x)) && map[y][x] != '1')
					return (false);
			}
			x++;
		}
		y++;
	}
	design->rows = y;
	design->columns = x;
	return (true);
}

bool	ft_feasible_map(char **map, t_design *design)
{
	if (ft_multiplelines(map, design))
		return (true);
	return (false);
}

char	*ft_read_file(int fd, t_error *error, char *str, t_design *design)
{
	char	*line;
	size_t	file_size;

	line = NULL;
	file_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (file_size == 0)
			ft_file_size(line, &file_size);
		if (!ft_check_dimension(line, error, file_size))
			ft_error_map("Invalid map", line);
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	if (!ft_completemap(str, design))
		ft_error_map("Invalid map", line);
	return (str);
}
