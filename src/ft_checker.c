/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/18 20:22:12 by davgalle         ###   ########.fr       */
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
	if (!ft_check_realmap(map))
		ft_freemap("Mapa no jugable", map);
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
	if (len < 7)
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

bool	ft_check_realmap(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	printf("Entra a recorrer **map\n");
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\n' || map[y][x] != '\0')
		{
			if (map[0][x] == '1')
			{
				count++;
				x++;
			}
			x++;
		}
		y++;
	}
	if (count == len)
		return (true);
	return (false);
}

void	ft_middle_map(char *str, t_design *design)
{
	int	i;
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			x++;
		if (str[i] == '0')
			y++;
		if (str[i] == 'E')
			z++;
		i++;
	}
	design->wall = x;
	design->space = y;
	design->exit = z;
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
			ft_error_map("Mapa no válido", line);
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	ft_completemap(str, design);
	return (str);
}
