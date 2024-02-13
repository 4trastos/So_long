/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:05 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 17:46:39 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_load_enemy(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'W')
				mlx_put_image_to_window(game->mlx, game->new_w,
					game->enemys, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}

void	ft_moveup(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playerup = game->playerupa;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
		game->playerup = game->playerupb;
		game->postcontrol = 0;
	}
}

void	ft_movedown(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playerdown = game->playerdowna;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
		game->playerdown = game->playerdownb;
		game->postcontrol = 0;
	}
}

void	ft_moveright(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playeright = game->playerighta;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
		game->playeright = game->playerightb;
		game->postcontrol = 0;
	}
}

void	ft_moveleft(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playerleft = game->playerlefta;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
		game->playerleft = game->playerleftb;
		game->postcontrol = 0;
	}
}
