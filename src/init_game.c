/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 15:01:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_init_game(char **map, t_design *design)
{
	t_game		game;

	game.design = design;
	game.collect = design->collect;
	game.floor = ft_matrixdup(map, design);
	game.mlx = mlx_init();
	game.new_w = mlx_new_window(game.mlx, design->columns * SIZE, design->rows * SIZE, "Beniat Txuri Urdina!!");
	game.img = mlx_new_image(game.mlx, design->columns * SIZE, design->rows * SIZE);
	ft_game(&game, map, design);
}

void	ft_game(t_game *game, char **map, t_design *design)
{
	game->width = design->columns * SIZE; 
	game->height = design->rows * SIZE;
	game->design = design;
	game->map = map;
	game->sprites = ft_load_sprites(game);
	ft_floor(game, design);
	ft_walls(map, game);
	ft_collects(map, game);
	ft_player(map, game, design);
//	load_player(game);
	ft_load_enemy(map, game);
//	mlx_loop_hook(game->mlx, ft_update, (void *)game);
//	mlx_hook(game->mew_w, 17, 0, end_game, (void *)game);
//	mlx_key_hook(game->new_w, key_hook, (void *)game);
	mlx_loop(game->mlx);
}
