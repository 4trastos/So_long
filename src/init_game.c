/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:36 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 16:16:57 by davgalle         ###   ########.fr       */
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
	game.new_w = mlx_new_window(game.mlx, 1920, 1080, "Beniat Txuri Urdina!!");
	ft_game(&game, map, design);
}

void	ft_game(t_game *game, char **map, t_design *design)
{
	char	*aux;

	aux = *map;
	game->width = design->columns * SIZE; 
	game->height = design->rows * SIZE + 80;
}
