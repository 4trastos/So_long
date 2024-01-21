/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/21 19:00:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_check_map(int fd, t_design *design, char **map)
{
	char	*str;
	t_error	*error;

	str = NULL;
	error = ft_new_error();
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	str = ft_read_file(fd, error, str, design);
	map = ft_split(str, '\n');
	if (!ft_check_border(map))
		ft_freemap("The map must be closed by walls", map);
	if (!ft_feasible_map(map))
		ft_freemap("The map is not feasible", map);
	free(str);
	free(error);
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
	while (len  > 0)
	{
		if (!is_valid_char(line[i], error))
			return (false);
		i++;
		len--;
	}
	return (true);
}

bool	ft_check_border(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (y == 0 || ft_getY(map, y))
			{
				if (map[y][x] != '1')
					return (false);
				else
					x++;
			}
			if (y != 0)
			{
				if ((x == 0 && map[y][x] != '1') || (ft_getX(map, x) && map[y][x] != '1'))
					return (false);
				else
					x++;
			}
		}
		y++;
	}
	return (true);
}

bool	ft_feasible_map(char **map)
{
	size_t	play_lines;
	size_t	boxes;

	boxes = ft_countboxes(map);
	play_lines = ft_playlines(map);
	if (play_lines == 1 && ft_singleline(map, boxes))
		return (true);
	if (play_lines > 1 && ft_multiplelines(map, play_lines, boxes))
		return (true);
	return (false);
}

char	*ft_read_file(int fd, t_error *error, char *str, t_design *design)
{
	char	*line;
	int		i;
	size_t		file_size;

	line = NULL;
	file_size = 0;
	i = 1;
	while (i > 0)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break;
		}
		if (file_size == 0)
			ft_file_size(line, &file_size);
		if (!ft_check_dimension(line, error, file_size))
			ft_error_map("Invalid map", line);
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	if (!ft_completemap(str, design)) //también se contempla que hay SOLO una E y P;  y como poco una C.
		ft_error_map("Invalid map", line);
	return (str);
}
