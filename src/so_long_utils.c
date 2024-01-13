/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:31:39 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 15:11:40 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

bool is_valid_char(char c, t_design *design) 
{
    return (c == design->wall || c == design->space || c == design->exit ||
            c == design->player || c == design->enemys || c == design->collect);
}

