/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:30 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/18 14:30:24 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_design	*ft_new_design()
{
	t_design	*new;

	new = (t_design *)malloc(sizeof(t_design));
	if (!new)
		return (NULL);
	new->wall = 0;
	new->space = 0;
	new->exit = 0;
	new->player = 0;
	new->enemys = 0;
	new->collect = 0;	
	return (new);
}

t_error	*ft_new_error()
{
	t_error	*new;

	new = (t_error *)malloc(sizeof(t_error));
	if (!new)
		return (NULL);
	new->wall = '1';
	new->space = '0';
	new->exit = 'E';
	new->player = 'P';
	new->enemys = 'W';
	new->collect = 'C';	
	return (new);
}

void	ft_restmap(char *str, t_design *design)
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
		if (str[i] == 'P')
			x++;
		if (str[i] == 'W')
			y++;
		if (str[i] == 'C')
			z++;
		i++;
	}
	design->player = x;
	design->enemys = y;
	design->collect = z;
}
