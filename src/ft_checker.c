/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:52:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 22:09:15 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_check_map(int fd, t_design *design)
{
	char	**map;
	char	*str;
	int		i;

	map = NULL;
	str = NULL;
	design = ft_new_design();
	ft_read_file(fd, design, str); // Leemos y guardamos en str para despues separlas porque no tengo cojones a leerlo en check_dimesion.
	map = ft_split(str, '\n'); //Hago esto como en push_swap y así separamos las lineas del mapa. Como en psuh_swap actualizamos el **argv)
	i = 0;
	printf("después de split %s\n", map[i]); //SOLO GUARDA LO ÚLTIMO DEL SPLIT.
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	free(str);
	return (map);
}

void	ft_read_file(int fd, t_design *design, char *str)
{
	char	*line; //La idea está sacada del main que hicimos del GNL. Es lo mismo tío!! No está acabado!!
	int		i;

	line = NULL;
	i = 1;
	while (i > 0)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!ft_check_dimension(line, design))
			ft_error_msg("Error de Dimensión\n", &line);
		str = ft_strdup(line); 
//		str = ft_strjoin(str, line); SI HACEMOS STRJOIN HACE SEGMENTATION FAUL
		printf("%s", str);
		free(line);
	}
	close(fd);
}

bool	ft_check_dimension(char *line, t_design *design)
{
	int	i;
	int	len;

	len = ft_strlen_custom(line);
	if (len < 7)
		return (false);
	i = 0;
	while (len  > 0)
	{
		if (!is_valid_char(line[i], design))
			return (false);
		i++;
		len--;
	}
	return (true);
}
/*
bool	ft_check_dimension(char **map, t_design *design)
{
	int x;
	int	y;
	int	z;

	printf("Entra a checkear argumentos y medidas\n");
	z = ft_strlen(map[0]);
	y = 0;
	while (map[y] != '\0')
		y++;
	if (y < 5)
		return (false);
	y = 0;
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\n')
		{	
			if (!is_valid_char(map[y][x], design))
				return (false);
			x++;
		}
		if (x < 7 || x != z)
			return (false);
		y++;
	}
	return (true);

}
*/
/*
char	**ft_check_map(int fd, t_design *design)
{
	char	*map;
	char	**aux;
	int		i;
	size_t	len;

	aux = NULL;
	i = 0;
	map = NULL;
	design = ft_new_design();
	while ((map = get_next_line(fd)) != NULL)
	{
		i++;
		len = ft_strlen(map);
		free(map);
	}
	close(fd);
	fd = open("maps/map_01.ber",  O_RDONLY);
	aux = (char **)malloc(i * len + 1);
	i = 0;
	if (i == 0)
	{
		while ((map = get_next_line(fd)) != NULL)
		{
			aux[i] = map;
			i++;
			free(map);
		}
	}
	close(fd);
	if (!ft_check_dimension(aux, design))
		ft_error_msg("Error de Dimensión\n", aux);
	return (aux);
}*/
