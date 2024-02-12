/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:55 by davgalle          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/12 21:00:12 by davgalle         ###   ########.fr       */
=======
/*   Updated: 2024/02/12 18:43:53 by usuario          ###   ########.fr       */
>>>>>>> cc13f97359c18d992a572bbbee4db337d87fa31b
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

int	key_press(int key, t_game *game)
{
	char	*moves_p;

	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->new_w);
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
	moves_p = ft_itoa(game->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}

void	move_w(t_game *game)
{
<<<<<<< HEAD
	if (game->map[game->posy / SIZE + UP][game->posx / SIZE] == 'E' && game->collect_count == 0)
		ft_win_game(game);
=======
/* 	printf("Posición de P en yp: %zu\n", design->yp);
	printf("Posición de P en xp: %zu\n", design->xp);
	printf("Posición de P en posy: %zu\n", game->posy / SIZE);
	printf("Posición de P en posx: %zu\n", game->posx / SIZE);
	printf("Posición de P en CHAR: %c\n", game->map[game->posy / SIZE][game->posx / SIZE]); */
	if (game->map[game->posy / SIZE + UP][game->posx / SIZE] == 'E' && game->collect_count == 0)
		ft_end_game(game);
>>>>>>> cc13f97359c18d992a572bbbee4db337d87fa31b
	if (game->map[game->posy / SIZE + UP][game->posx / SIZE] == '0' || game->map[game->posy / SIZE + UP][game->posx / SIZE] == 'C')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		if (game->map[game->posy / SIZE + UP][game->posx / SIZE] == 'C')
			game->collect_count--;
		game->map[game->posy / SIZE + UP][game->posx / SIZE] = 'P';
		game->posy = game->posy - SIZE;
		game->moves++;
		ft_moveup(game);
		mlx_put_image_to_window(game->mlx, game->new_w, game->playerup, game->posx, game->posy);
	}
}

void	move_s(t_game *game)
{
	if (game->map[game->posy / SIZE + DOWN][game->posx / SIZE] == 'E' && game->collect_count == 0)
		ft_win_game(game);
	if (game->map[game->posy / SIZE + DOWN][game->posx / SIZE] == '0' || game->map[game->posy / SIZE + DOWN][game->posx / SIZE] == 'C')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		if (game->map[game->posy / SIZE + DOWN][game->posx / SIZE] == 'C')
			game->collect_count--;
		game->map[game->posy / SIZE + DOWN][game->posx / SIZE] = 'P';
		game->posy = game->posy + SIZE;
		game->moves++;
		ft_movedown(game);
		mlx_put_image_to_window(game->mlx, game->new_w, game->playerdown, game->posx, game->posy);
	}
}

void	move_a(t_game *game)
{
	if (game->map[game->posy / SIZE][game->posx / SIZE - 1] == 'E' && game->collect_count == 0)
		ft_win_game(game);
	if (game->map[game->posy / SIZE][game->posx / SIZE - 1] == '0' || game->map[game->posy / SIZE][game->posx / SIZE - 1] == 'C')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		if (game->map[game->posy / SIZE][game->posx / SIZE - 1] == 'C')
			game->collect_count--;
		game->map[game->posy / SIZE][game->posx / SIZE - 1] = 'P';
		game->posx = game->posx - SIZE;
		game->moves++;
		ft_moveleft(game);
		mlx_put_image_to_window(game->mlx, game->new_w, game->player, game->posx, game->posy);
	}
}

void	move_d(t_game *game)
{
	if (game->map[game->posy / SIZE][game->posx / SIZE + 1] == 'E' && game->collect_count == 0)
		ft_win_game(game);
	if (game->map[game->posy / SIZE][game->posx / SIZE + 1] == '0' || game->map[game->posy / SIZE][game->posx / SIZE + 1] == 'C')
	{
		if ((game->posx / SIZE) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->new_w, game->grass, game->posx, game->posy);
		else
			mlx_put_image_to_window(game->mlx, game->new_w, game->grasstwo, game->posx, game->posy);
		game->map[game->posy / SIZE][game->posx / SIZE] = '0';
		if (game->map[game->posy / SIZE][game->posx / SIZE + 1] == 'C')
			game->collect_count--;
		game->map[game->posy / SIZE][game->posx / SIZE + 1] = 'P';
		game->posx = game->posx + SIZE;
		game->moves++;
		ft_moveright(game);
		mlx_put_image_to_window(game->mlx, game->new_w, game->playeright, game->posx, game->posy);
	}
}
