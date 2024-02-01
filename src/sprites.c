/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:07:03 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 20:17:58 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

t_sprite	ft_load_sprites(t_game *game)
{
	int	size;

	size = SIZE;
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "textures/xpm/cono.xpm", &size, &size);
	game->sprites.grass = mlx_xpm_file_to_image(game->mlx, "textures/xpm/grass_01.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/xpm/champions.xpm", &size, &size);
	game->sprites.enemys = mlx_xpm_file_to_image(game->mlx, "textures/xpm/ghost.xpm", &size, &size);
	return (game->sprites);
}

int	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.grass);
	mlx_destroy_image(game->mlx, game->sprites.player);
	mlx_destroy_image(game->mlx, game->sprites.exit);
	return (0);
}

void	ft_playerlist(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}
