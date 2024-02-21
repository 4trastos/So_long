/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:07:34 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/21 16:38:00 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w,
		game->init, game->posx, game->posy);
}

void	ft_countermov(t_game *game, char *moves_p)
{
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass,
		game->width - 70, game->height - 20);
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass,
		game->width - 125, game->height - 20);
	mlx_string_put(game->mlx, game->new_w, game->width - 120,
		game->height - 20, 0xFFFFFF, "MOVES:");
	mlx_string_put(game->mlx, game->new_w, game->width - 40,
		game->height - 20, 0xFFFFFF, moves_p);
}

void	ft_finish(t_game *game)
{
	mlx_destroy_window(game->mlx, game->new_w);
	ft_error_msg("Congrats, you win!!!! 🥳🏆\n", NULL);
}
