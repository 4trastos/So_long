/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:31:39 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/18 14:50:53 by nicgonza         ###   ########.fr       */
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

bool is_valid_char(char c, t_error *error) 
{
	t_error	*aux;

	aux = error;
	printf("Entra esta mierda %c\n", c);
	printf("Entra a validar los char\n");
    if (c == aux->wall) 
		return (printf("true\n"), true);
	else if (c == aux->space)
		return (printf("true\n"), true);
	else if (c == aux->exit)
		return (printf("true\n"), true);
	else if (c == aux->player) 
		return (printf("true\n"), true);
	else if (c == aux->enemys) 
		return (printf("true\n"), true);
	else if (c == aux->collect)
		return (printf("true\n"), true);
	else
	{
	printf("false");
	return (false);
	}
}

size_t	ft_strlen_custom(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
		printf("%zu", i);
	}
	return (i);
}

void	ft_file_size(char *str, size_t *size)
{
	if (*size == 0)
		*size = ft_strlen(str);
	else
		*size = *size + ft_strlen(str) + 1;
}
