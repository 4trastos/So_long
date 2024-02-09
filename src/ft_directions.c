/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:00:52 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:30 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	move_w(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (game->map[y]!= NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x + UP] != '1' || game->map[y][x + UP] != 'W')
			{
				game->moves++;
				if (game->map[y][x + UP] == 'C')
				{
					game->collect--;
					game->map[y][x] = '0';
					game->map[y][x + UP] = 'P';
				}
				if (game->map[y][x + UP] == 'E')
					check_exit(game, game->map[y][x + UP]);
				/* if (game->npccontrol == 0)
				{
					game->npcstart = game->npcback;
					game->npccontrol = 1;
				}
				else
				{
					game->npcstart = game->npcbmv;
					game->npccontrol = 0;
				} */
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
