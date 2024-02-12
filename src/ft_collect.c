/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:02:12 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/12 20:01:13 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_collects(char **map, t_game *game, t_design *design)
{
	int	x;
	int	y;

	(void)design;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->new_w, game->collect, SIZE * x, SIZE * y);
				game->collect_count++;
			}
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->new_w, game->exit, SIZE * x, SIZE * y);
			else if (map[y][x] == 'W')
				mlx_put_image_to_window(game->mlx, game->new_w, game->enemys, SIZE * x, SIZE * y);
			x++;
		}
		y++;
	}
}

void	ft_win_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->new_w);
	ft_error_msg("Congratulations you win🏆!", NULL);
}

void	ft_putmoves(int c)
{
	 write(1, (char*)&c, 1);
	write(1, "\n", 1);
}