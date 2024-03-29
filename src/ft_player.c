/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:07:34 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/21 17:07:54 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w,
		game->init, game->posx, game->posy);
}

void	ft_finish(t_game *game)
{
	mlx_destroy_window(game->mlx, game->new_w);
	ft_error_msg("Congrats, you win!!!! 🥳🏆\n", NULL);
}
