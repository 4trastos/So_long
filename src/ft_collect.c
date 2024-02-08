/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:02:12 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/08 18:56:17 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_collects(char **map, t_game *game, t_design *design)
{
	int	x;
	int	y;

	game->posx = design->xe;
	game->posy = design->ye;
//	game->pwx = design->xw;
//	game->pwy = design->yw;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->new_w, game->collect, SIZE * x, SIZE * y);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->new_w, game->exit, SIZE * game->posx, SIZE * game->posy);
			else if (map[y][x] == 'W')
				mlx_put_image_to_window(game->mlx, game->new_w, game->enemys, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}
