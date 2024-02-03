/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:10:18 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 21:21:51 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

bool	check_exit(t_game *game, char letter)
{
	if (letter == 'E' && game->collect == 0)
	{
		write(1, "Congrats, you win 🥳🏆\n", 27);
//		ft_free(game);
		free(game);
	}
	if (letter == 'E' && game->collect != 0)
	{
		write(1, "You need to collect all the shields\n", 37);
		return (false);
	}
	else
		return (true);
}
