/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:07:03 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 18:12:45 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_load_sprites(t_game *game)
{
	int	size;

	size = SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/Water.xpm", &size, &size);
	game->grass = mlx_xpm_file_to_image(game->mlx, "textures/Grass.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/Gatuflas_frente_1.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/Exit.xpm", &size, &size);
	game->enemys = mlx_xpm_file_to_image(game->mlx, "textures/Enemy.xpm", &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/coleccionable_1.xpm", &size, &size);
}

int	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	return (0);
}

