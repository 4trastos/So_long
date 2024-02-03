/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:00:52 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/03 15:03:58 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

t_list	*ft_north(t_game *game, char *road, int i)
{
	t_list	*animation;
	char	*str;

	animation = NULL;
	if (road)
	{
		str = ft_strjoin(road, "xmp/ghost/ghost01.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i))); 
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost02.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost03.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost04.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		return (animation);
	}
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_up0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_up1.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_up0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_up1.xpm", &i, &i)));
	return (animation);
}

t_list	*ft_south(t_game *game, char *road, int i)
{
	t_list	*animation;
	char	*str;

	animation = NULL;
	if (road)
	{
		str = ft_strjoin(road, "xmp/ghost/ghost01.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost02.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost03.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost04.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		return (animation);
	}
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_down0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_down1.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_down0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_down1.xpm", &i, &i)));
	return (animation);
}

t_list	*ft_west(t_game *game, char *road, int i)
{
	t_list	*animation;
	char	*str;

	animation = NULL;
	if (road)
	{
		str = ft_strjoin(road, "xmp/ghost/ghost01.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i))); 
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost02.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost03.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost04.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		return (animation);
	}
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_left0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_left1.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_left2.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_left3.xpm", &i, &i)));
	return (animation);
}

t_list	*ft_east(t_game *game, char *road, int i)
{
	t_list	*animation;
	char	*str;

	animation = NULL;
	if (road)
	{
		str = ft_strjoin(road, "xmp/ghost/ghost01.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost02.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost03.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		str = ft_strjoin(road, "xmp/ghost/ghost04.xpm");
		ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, str, &i, &i)));
		free(str);
		return (animation);
	}
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_right0.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_right1.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xpm/beniat/naked/beniat_right2.xpm", &i, &i)));
	ft_stack_node(&animation, ft_create_node(mlx_xpm_file_to_image(game->mlx, "xmp/beniat/naked/beniat_right3.xpm", &i, &i)));
	return (animation);
}

void	ft_put_stopped(t_game *game, t_player *beniat)
{
	if (beniat->dir == N)
		mlx_put_image_to_window(game->mlx, game->new_w, beniat->sprites.up_back->content, beniat->posx * SIZE, beniat->posy * SIZE);
	if (beniat->dir == S)
		mlx_put_image_to_window(game->mlx, game->new_w, beniat->sprites.down_back->content, beniat->posx * SIZE, beniat->posy * SIZE);
	if (beniat->dir == E)
		mlx_put_image_to_window(game->mlx, game->new_w, beniat->sprites.right_back->content, beniat->posx * SIZE, beniat->posy * SIZE);
	if (beniat->dir == W)
		mlx_put_image_to_window(game->mlx, game->new_w, beniat->sprites.left_back->content, beniat->posx * SIZE, beniat->posy * SIZE);
}
