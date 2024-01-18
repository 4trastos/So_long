/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:31:39 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/18 12:22:41 by nicgonza         ###   ########.fr       */
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
	printf("Entra a validar los char\n");
    if (c == error->wall || c == error->space || c == error->exit ||
            c == error->player || c == error->enemys || c == error->collect)
		return (true);
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
