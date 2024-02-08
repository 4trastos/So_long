/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:41:23 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/29 18:44:04 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnrcmp(char *argv, char *str, int count)
{
	int	i;

	i = ft_strlen(argv) - 1;
	count = 3;
	while (count >= 0 && i >= 0)
	{
		if (argv[i] != str[count])
			return (1);
		i--;
		count--;
	}
	return (0);
}

bool	is_valid_char(char c, t_error *error)
{
	t_error	*aux;

	aux = error;
	if (c == aux->wall)
		return (true);
	else if (c == aux->space)
		return (true);
	else if (c == aux->exit)
		return (true);
	else if (c == aux->player)
		return (true);
	else if (c == aux->enemys)
		return (true);
	else if (c == aux->collect)
		return (true);
	else
		return (false);
}

size_t	ft_strlen_custom(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

void	ft_file_size(char *str, size_t *size)
{
	if (*size == 0)
		*size = ft_strlen(str);
	else
		*size = *size + ft_strlen(str) + 1;
}

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
