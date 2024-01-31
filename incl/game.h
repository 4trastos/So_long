/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/31 12:54:03 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

void	window(void);

//** STRUCT MLX **

typedef struct	s_data
{
	void	*img;
	char	*addr; //añadir resolucion
	int		bits; //bits or pixel
	int		line_length;
	int		endian; //el orden de los bites
}				t_data;

#endif
