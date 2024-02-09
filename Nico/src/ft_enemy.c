/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/create_nodes.c
/*   Created: 2024/02/02 21:24:28 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/08 15:01:12 by davgalle         ###   ########.fr       */
=======
/*   Created: 2024/02/02 15:15:05 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 17:03:58 by nicgonza         ###   ########.fr       */
>>>>>>> 355d1e447951aa493606ecb35653b7b53b4c4f04:Nico/src/ft_enemy.c
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

<<<<<<< HEAD:src/create_nodes.c
t_game	*ft_new_game(void)
{
	t_game	*new;

	new = (t_game *)malloc(sizeof(t_game));
	if (!new)
		return (NULL);
	new->width = 0;
	new->height = 0;
	new->collect = 0;
	new->moves = 0;
	return (new);
}

void	ft_stack_node(t_list **animation, t_list *new)
=======
void	ft_load_enemy(char **map, t_game *game)
>>>>>>> 355d1e447951aa493606ecb35653b7b53b4c4f04:Nico/src/ft_enemy.c
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

int	ft_free_matrix(t_game *game)
{
	if (game->map)
		free(game->map);
	if (game)
		free(game);
	exit(0);
}