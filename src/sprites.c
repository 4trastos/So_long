/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:07:03 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/02 19:27:14 by davgalle         ###   ########.fr       */
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
	game->sprites.grasstwo = mlx_xpm_file_to_image(game->mlx, "textures/xpm/grass_02.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/xpm/champions.xpm", &size, &size);
	game->sprites.enemys = mlx_xpm_file_to_image(game->mlx, "textures/xpm/ghost/ghost01.xpm", &size, &size);
	game->sprites.collect = mlx_xpm_file_to_image(game->mlx, "textures/xpm/reala.xpm", &size, &size);
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

