/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/20 16:53:53 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_init_game(char **map, t_design *design)
{
	t_game		game;

	game.design = design;
	load_data(map, design);
	game.collect_count = design->collect;
	game.mlx = mlx_init();
	game.new_w = mlx_new_window(game.mlx, design->columns * SIZE,
			design->rows * SIZE, "Beniat Txuri Urdina!!");
	ft_game(&game, map, design);
}

void	ft_game(t_game *game, char **map, t_design *design)
{
	game->width = design->columns * SIZE;
	game->height = design->rows * SIZE;
	game->design = design;
	game->map = map;
	game->moves = 0;
	game->postcontrol = 0;
	game->posx = design->xp * SIZE;
	game->posy = design->yp * SIZE;
	game->posxe = design->xe * SIZE;
	game->posye = design->ye * SIZE;
	ft_load_sprites(game);
	ft_loadsprites(game);
	ft_floor(game, design);
	ft_walls(map, game);
	ft_collects(map, game);
	ft_player(game);
	mlx_key_hook(game->new_w, key_press, game);
	mlx_hook(game->new_w, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->new_w);
	exit(0);
	return (0);
}
