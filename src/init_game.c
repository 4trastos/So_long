/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 20:21:05 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_init_game(char **map, t_design *design)
{
	t_game		game;

	game.design = design;
	game.collect = design->collect;
	game.floor = ft_matrixdup(map);
	game.mlx = mlx_init();
	game.new_w = mlx_new_window(game.mlx, design->columns * SIZE, design->rows * SIZE, "Beniat Txuri Urdina!!");
	ft_game(&game, map, design);
}

void	ft_game(t_game *game, char **map, t_design *design)
{
	game->width = design->columns * SIZE; 
	game->height = design->rows * SIZE;
	game->design = design;
	game->map = map;
	game->sprites = ft_load_sprites(game);
	ft_playerlist(map, game);
//	ft_enemy_mov(game);
//	ft_player_mov(game);
	mlx_loop(game->mlx);
}
