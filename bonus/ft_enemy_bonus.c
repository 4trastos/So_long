/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:05 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/13 14:48:27 by davgalle         ###   ########.fr       */
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
				mlx_put_image_to_window(game->mlx, game->new_w, game->enemys, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}
void	ft_moveup(t_game *game)
{
	if (game->postcontrol == 0)
	{
    	game->playerup = game->playerupA;
    	game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
    	game->playerup = game->playerupB;
    	game->postcontrol = 0;
	}
}

void	ft_movedown(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playerdown = game->playerdownA;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
   		game->playerdown = game->playerdownB;
    	game->postcontrol = 0;
	}
}

void	ft_moveright(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playeright = game->playerightA;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
   		game->playeright = game->playerightB;
    	game->postcontrol = 0;
	}
}

void	ft_moveleft(t_game *game)
{
	if (game->postcontrol == 0)
	{
		game->playerleft = game->playerleftA;
		game->postcontrol = 1;
	}
	else if (game->postcontrol == 1)
	{
   		game->playerleft = game->playerleftB;
    	game->postcontrol = 0;
	}
}