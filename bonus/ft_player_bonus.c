/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:07:34 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 14:50:07 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_player(char **map, t_game *game, t_design *design)
{
	(void)map;
	(void)design;
	mlx_put_image_to_window(game->mlx, game->new_w, game->init, game->posx, game->posy);
}
