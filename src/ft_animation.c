/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:55 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/09 23:08:46 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

int	key_press(int key, t_game *game, t_design *design)
{
	char	*moves_p;

	(void)moves_p;
	(void)game;
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->new_w);
		exit (0);
	}
	 if (key == 13)
		move_w(game, design);
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

void	move_w(t_game *game, t_design *design)
{
	printf("Posición de P en yp: %zu\n", design->yp);
	printf("Posición de P en xp: %zu\n", design->xp);
	printf("Posición de P en posy: %zu\n", game->posy / SIZE);
	printf("Posición de P en posx: %zu\n", game->posx / SIZE);
	printf("Posición de P en CHAR: %c\n", game->map[game->posy / SIZE][game->posx / SIZE]);
	if (game->map[game->posy / SIZE + UP][game->posx / SIZE] == '0')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		game->map[game->posy / SIZE + UP][game->posx / SIZE] = 'P';
		game->posy = game->posy - SIZE;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
	}
}

void	move_s(t_game *game)
{
	if (game->map[game->posy / SIZE + DOWN][game->posx / SIZE] == '0')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		game->map[game->posy / SIZE + DOWN][game->posx / SIZE] = 'P';
		game->posy = game->posy + SIZE;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
	}
}

void	move_a(t_game *game)
{
	if (game->map[game->posy / SIZE][game->posx / SIZE - 1] == '0')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		game->map[game->posy / SIZE][game->posx / SIZE - 1] = 'P';
		game->posx = game->posx - SIZE;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
	}
}

void	move_d(t_game *game)
{
	if (game->map[game->posy / SIZE][game->posx / SIZE + 1] == '0')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		game->map[game->posy / SIZE][game->posx / SIZE + 1] = 'P';
		game->posx = game->posx + SIZE;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
	}
}

/*
void	move_w(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width_l] != '1'
		&& !check_exit(d, d->big_line[i - d->width_l]))
	{
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcback;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcbmv;
			d->npccontrol = 0;
		}
	}
	print_map(d);
} */
