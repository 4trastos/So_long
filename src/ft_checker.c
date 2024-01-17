/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/17 20:41:14 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_check_map(int fd, t_design *design)
{
	char	**map;
	char	*str;
	t_error	*error;

	map = NULL;
	str = NULL;
	design = NULL;
	error = ft_new_error();
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	str = ft_read_file(fd, error, str, design);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

bool	ft_check_dimension(char *line, t_error *error, size_t file_size)
{
	int		i;
	size_t	len;

	printf("STR en Ckec Dimension: %s\n", line);
	printf("file_size: %zu\n", file_size);
	len = ft_strlen_custom(line);
	printf("len: %zu\n", len);
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
	printf("Retorna true\n");
	return (true);
}

bool	ft_check_realmap(char *str, t_design *design)
{
	design = ft_new_design();
	ft_middle_map(str, design);
	ft_restmap(str, design);
	return (true);
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
		printf("Linea: %s\n", line);
		if (!line)
			break;
		if (file_size == 0)
			ft_file_size(line, &file_size);
		if (!ft_check_dimension(line, error, file_size))
			ft_error_map("Mapa no válido1", line);
		str = ft_strjoin(str, line);
		printf("STR despues del JOIN: \n%s\n", str);
		free(line);
	}
	close(fd);
	if (!ft_check_realmap(str, design)) // check de mapa jugable o no.
		ft_error_map("Mapa no válido", str);
	return (str);
}
