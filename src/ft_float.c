/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:57:28 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/21 17:06:57 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_exit(t_game *game)
{
	game->map[game->posye / SIZE][game->posxe / SIZE] = 'E';
	mlx_put_image_to_window(game->mlx, game->new_w,
		game->exit, game->posxe, game->posye);
}
