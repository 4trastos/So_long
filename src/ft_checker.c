/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/19 23:32:18 by davgalle         ###   ########.fr       */
=======
/*   Updated: 2024/01/19 17:24:17 by nicgonza         ###   ########.fr       */
>>>>>>> 0fbf807ecc8f521bf47369e2689876e73312870e
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
		ft_freemap("El mapa debe estar cerrado por muros", map);
<<<<<<< HEAD
	if (!ft_feasible_map(map))
		ft_freemap("El mapa no es completable", map);
//	if (!ft_check_realmap(map))
//		ft_freemap("Mapa no jugable", map);
=======
	if (!ft_map_completable)
		ft_freemap("El mapa no es completable", map);
>>>>>>> 0fbf807ecc8f521bf47369e2689876e73312870e
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
<<<<<<< HEAD
	printf("Entra a buscar muros\n");
	while (map[y] != '\0')
	{
		x = 0;
		printf("Recorre Y: %s\n", map[y]);
		while (map[y][x] != '\0')
		{
			printf("Dentro del segundo while\n");
			printf("contenido de X: %c\n", map[y][x]);
			printf("Línea: %i\n", y);
			if (y == 0 || y == ft_getY(map)) //solo check primera linea. Peta la función. He probado con un bool pero tampoco sirve
			{
				if (map[y][x] != '1')
					return (printf("Muros falsos en primera o última  línea\n"), false);
				else
					x++;
			}
//			if (y != 0 && y != ft_getY(map))
			if (y != 0)
			{
				printf("Y es diferente a 0\n");
				printf("Entra a recorrer la segunda línea\n");
				if ((x == 0 || x == ft_getX(map)) && map[y][x] != '1')
					return (printf("Muros false\n"), false);
=======
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if ((y == 0 || y == ft_getY(map)) && map[y][x] == '1')
				x++;
			if (y != 0 && y != ft_getY(map))
			{
				if ((x == 0 || x == ft_getX(map)) && map[y][x] != '1')
					return (false);
>>>>>>> 0fbf807ecc8f521bf47369e2689876e73312870e
				else
					x++;
			}
		}
		y++;
	}
<<<<<<< HEAD
	return (printf("Cerrados por muros TRUE\n"), true);
}

bool	ft_feasible_map(char **map)
=======
	return (true);
}

bool	ft_map_completable(char **map)
>>>>>>> 0fbf807ecc8f521bf47369e2689876e73312870e
{
	int		y;
	int 	x;
	bool	b;

	y = 1;
	b = true;
	while (map[y] != '\0')
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if(map[y][x] != '1')
			{
				if (map[y][x + 1] == '1' && map[y][x - 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
					b = false;
				else
					x++;
			}
			else
				x++;
		}
		y++;
	}
	return (b);
}

<<<<<<< HEAD
/*
bool	ft_check_realmap(char **map)
=======
/*bool	ft_check_realmap(char **map)
>>>>>>> 0fbf807ecc8f521bf47369e2689876e73312870e
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
}*/

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
}*/

char	*ft_read_file(int fd, t_error *error, char *str, t_design *design)
{
	char	*line;
	int		i;
	size_t		file_size;

	line = NULL;
	file_size = 0;
	design = NULL;
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
	//ft_completemap(str, design);
	return (str);
}
