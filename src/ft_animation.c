/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:55 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 15:05:55 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_anim_north(t_game *game, t_player *play)
{
	t_player	*aux;

	aux = play;
	if (!game->n_frames)
		aux->sprites.up = aux->sprites.up->next;
	if (!aux->sprites.up)
		aux->sprites.up = aux->sprites.up_back;
	mlx_put_image_to_window(game->mlx, game->new_w, aux->sprites.up->content, aux->posx, aux->posy);
}

void	ft_anim_south(t_game *game, t_player *play)
{
	t_player	*aux;

	aux = play;
	if (!game->n_frames)
		aux->sprites.down = aux->sprites.down->next;
	if (!aux->sprites.down)
		aux->sprites.down = aux->sprites.down_back;
	mlx_put_image_to_window(game->mlx, game->new_w, aux->sprites.down->content, aux->posx, aux->posy);
}

void	ft_anim_west(t_game *game, t_player *play)
{
	t_player	*aux;

	aux = play;
	if (!game->n_frames)
		aux->sprites.left = aux->sprites.left->next;
	if (!aux->sprites.left)
		aux->sprites.left = aux->sprites.left_back;
	mlx_put_image_to_window(game->mlx, game->new_w, aux->sprites.left->content, aux->posx, aux->posy);
}

void	ft_anim_east(t_game *game, t_player *play)
{
	t_player	*aux;

	aux = play;
	if (!game->n_frames)
		aux->sprites.right = aux->sprites.right->next;
	if (!aux->sprites.right)
		aux->sprites.right = aux->sprites.right_back;
	mlx_put_image_to_window(game->mlx, game->new_w, aux->sprites.right->content, aux->posx, aux->posy);
}
