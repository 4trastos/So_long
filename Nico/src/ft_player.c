/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:07:34 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 18:35:27 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_player(char **map, t_game *game, t_design *design)
{

	map = NULL;
	printf("Posicon X: %zu\n", design->xp);
	printf("Posicon Y: %zu\n", design->yp);
	mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
}
/*
void	ft_player(char **map, t_game *game)
{
	t_player	*gato;
	int	x;
	int	y;

	gato = game->player;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, SIZE * x, SIZE * y);
//				mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, gato->pos.xp, gato->pos.yp);
			x++;
		}
		y++;
	}
}*/
