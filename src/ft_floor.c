/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:50:56 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 16:55:20 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_floor(t_game *game, t_design *design)
{
	int	i;
	int	j;

	game->collect_count = design->collect;
	j = 0;
	while (j <= design->rows * SIZE)
	{
		i = 0;
		while (i <= design->columns * SIZE)
		{
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, i, j);
			i = i + SIZE;
			if (i <= design->columns * SIZE)
			{
				mlx_put_image_to_window(game->mlx, game->new_w,
					game->grasstwo, i, j);
				i = i + SIZE;
			}
		}
		j = j + SIZE;
	}
}

void	ft_walls(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->new_w,
					game->wall, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}
