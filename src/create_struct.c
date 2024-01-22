/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:30 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/22 17:23:12 by davgalle         ###   ########.fr       */
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
	new->yp = 0;
	new->xp = 0;
	new->yc = 0;
	new->xc = 0;
	new->ye = 0;
	new->xe = 0;
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
