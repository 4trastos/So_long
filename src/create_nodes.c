/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:24:28 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/02 22:21:45 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_stack_node(t_list **a, t_list *new)
{
	t_list	*aux;

	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
	new->next = NULL;
}

t_list	*ft_create_node(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
}
