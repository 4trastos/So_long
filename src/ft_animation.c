/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:55 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/08 18:43:58 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

int	key_press(int key, t_game *game)
{
	char	*moves_p;

	(void)moves_p;
	(void)game;
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->new_w);
//		ft_free(game);
		exit (0);
	}
	 if (key == 13)
		move_w(game);
	if (key == 0)
		move_a(game);
	if (key == 1)
		move_s(game);
	if (key == 2)
		move_d(game);
//	moves_p = ft_itoa(game->moves);
//	write(1, moves_p, ft_strlen(moves_p));
//	if (moves_p)
//		free(moves_p);
//	write(1, "\n", 1);
	return (0);
}

void	move_w(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (game->map[y]!= NULL)
	{
		x = 0;
		while (game->map[y][x] != 'P')
		{
			if (game->map[y][x + UP] != '1'
				&& !check_exit(game, game->map[y][x + UP]))
			{
				game->moves++;
				if (game->map[y][x + UP] == 'C')
				game->collect--;
				game->map[y][x] = '0';
				game->map[y][x + UP] = 'P';
				if (game->npccontrol == 0)
				{
					game->npcstart = game->npcback;
					game->npccontrol = 1;
				}
				else
				{
					game->npcstart = game->npcbmv;
					game->npccontrol = 0;
				}
			}
			x++;
		}
		y++;
	}
//	print_map(map);
}
void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (game->big_line[i] != 'P')
		i++;
	if (game->big_line[i + game->width_l] != '1'
		&& !check_exit(game, game->big_line[i + game->width_l]))
	{
		game->moves++;
		if (game->big_line[i + game->width_l] == 'C')
			game->collect--;
		game->big_line[i] = '0';
		game->big_line[i + game->width_l] = 'P';
		if (game->npccontrol == 0)
		{
			game->npcstart = game->npc;
			game->npccontrol = 1;
		}
		else
		{
			game->npcstart = game->npcmv;
			game->npccontrol = 0;
		}
	}
//	print_map(map);
}

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (game->big_line[i] != 'P')
		i++;
	if (game->big_line[i - 1] != '1' && !check_exit(game, game->big_line[i - 1]))
	{
		game->moves++;
		if (game->big_line[i - 1] == 'C')
			game->collect--;
		game->big_line[i] = '0';
		game->big_line[i - 1] = 'P';
		if (game->npccontrol == 0)
		{
			game->npcstart = game->npcleft;
			game->npccontrol = 1;
		}
		else
		{
			game->npcstart = game->npclmv;
			game->npccontrol = 0;
		}
	}
//	print_map(map);
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (game->big_line[i] != 'P')
		i++;
	if (game->big_line[i + 1] != '1' && !check_exit(game, game->big_line[i + 1]))
	{
		game->moves++;
		if (game->big_line[i + 1] == 'C')
			game->collect--;
		game->big_line[i] = '0';
		game->big_line[i + 1] = 'P';
		if (game->npccontrol == 0)
		{
			game->npcstart = game->npcright;
			game->npccontrol = 1;
		}
		else
		{
			game->npcstart = game->npcrmv;
			game->npccontrol = 0;
		}
	}
//	print_map(map);
}
