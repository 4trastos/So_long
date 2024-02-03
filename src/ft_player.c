/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:07:34 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 16:18:53 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	load_player(t_game *game)
{
	t_player	*beniat;
	int			i;

	i = 0;
	beniat = game->player;
	while (beniat)
	{
		beniat->sprites.up = ft_north(game, NULL, i);
		beniat->sprites.up_back = beniat->sprites.up;
		beniat->sprites.down = ft_south(game, NULL, i);
		beniat->sprites.down_back = beniat->sprites.down;
		beniat->sprites.left = ft_west(game, NULL, i);
		beniat->sprites.left_back = beniat->sprites.left;
		beniat->sprites.right = ft_east(game, NULL, i);
		beniat->sprites.right_back = beniat->sprites.right;
		beniat = beniat->next;
	}
}

void	ft_put_player(t_game *game)
{
	t_player	*beniat;

	beniat = game->player;
	while (beniat)
	{
		mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, beniat->posx, beniat->posy);
		if (beniat->dir == N && beniat->moving)
			ft_anim_north(game, beniat);
		if (beniat->dir == S && beniat->moving)
			ft_anim_south(game, beniat);
		if (beniat->dir == E && beniat->moving)
			ft_anim_east(game, beniat);
		if (beniat->dir == W && beniat->moving)
			ft_anim_west(game, beniat);
		if (beniat->dir == ST)
			mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, beniat->posx, beniat->posy);
		else if (!beniat->moving)
			ft_put_stopped(game, beniat);
		beniat = beniat->next;
	}
}

void	ft_player(char **map, t_game *game, t_design *design)
{
	t_player	*beniat;

	map = NULL;
	beniat = game->player;
	beniat->posx = design->xp * SIZE;
	beniat->posy = design->yp * SIZE;
	printf("Posicon X: %zu\n", design->xp);
	printf("Posicon Y: %zu\n", design->yp);
	mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, beniat->posx, beniat->posy);
}
/*
void	ft_player(char **map, t_game *game)
{
	t_player	*beniat;
	int	x;
	int	y;

	beniat = game->player;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, SIZE * x, SIZE * y);
//				mlx_put_image_to_window(game->mlx, game->new_w, game->sprites.player, beniat->pos.xp, beniat->pos.yp);
			x++;
		}
		y++;
	}
}*/
