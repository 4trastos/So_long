/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:07:03 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/12 20:54:10 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_load_sprites(t_game *game)
{
	int	size;

	size = SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/xpm/cono.xpm", &size, &size);
	game->grass = mlx_xpm_file_to_image(game->mlx, "textures/xpm/grass_01.xpm", &size, &size);
	game->grasstwo = mlx_xpm_file_to_image(game->mlx, "textures/xpm/grass_02.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_left.xpm", &size, &size);
	game->playerupA = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_up01.xpm", &size, &size);
	game->playerupB = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_up02.xpm", &size, &size);
	game->playerdownA = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_down01.xpm", &size, &size);
	game->playerdownB = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_down02.xpm", &size, &size);
	game->playeright = mlx_xpm_file_to_image(game->mlx, "textures/xpm/beniat_right.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/xpm/champions.xpm", &size, &size);
	game->enemys = mlx_xpm_file_to_image(game->mlx, "textures/xpm/ghost/ghost01.xpm", &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/xpm/reala.xpm", &size, &size);
}

int	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->enemys);
	mlx_destroy_image(game->mlx, game->grasstwo);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->playerdown);
	return (0);
}
