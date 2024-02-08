/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:55 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 18:53:05 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

int	key_press(int key, t_game *game)
{
	if (key == 13)
		move_w(game);
	if (key == 0)
		move_a(game);
	if (key == 1)
		move_s(game);
	if (key == 2)
		move_d(game);
	return (0);
}

void	move_w(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
	game->posy = game->posy - SIZE;
	mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
}
void	move_s(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
	game->posy = game->posy + SIZE;
	mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
}


void	move_a(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
	game->posx = game->posx - SIZE;
	mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
}

void	move_d(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
	game->posx = game->posx + SIZE;
	mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
}
