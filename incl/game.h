/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/12 18:43:44 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define SIZE 64

void	window(void);

//** DIRECTION **

enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

//** STRUCT MLX **
/*
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_pl_sprite
{
	t_list			*up;
	t_list			*up_back;
	t_list			*down;
	t_list			*down_back;
	t_list			*left;
	t_list			*left_back;
	t_list			*right;
	t_list			*right_back;
}				t_pl_sprite;*/

typedef struct	s_game
{
	int				width;
	int				height;
	int				collect_count;
	int				moves;
	int				errors;
	int				npccontrol;
	int				width_l;
	t_design		*design;
	size_t			posx;
	size_t			posy;
	void			*mlx;
	void			*new_w;
	void			*img;
	void			*wall;
	void			*grass;
	void			*grasstwo;
	void			*exit;
	void			*player;
	void			*collect;
	void			*enemys;
	void			*none;
	void			*npcstart;
	void			*npcback;
	void			*npcbmv;
	void			*npcleft;
	void			*npcright;
	void			*npclmv;
	void			*npcrmv;
	void			*npc;
	void			*npcmv;
	char			**map;
	char			**floor;
	char			*big_line;
	int				n_frames;
	int				g_rate;
	int				panic_mode;
}				t_game;

//** WINDOW **

void		ft_window(char **map, t_design *design);
void		*mlx_init();
void		ft_load_sprites(t_game *game);
void		ft_floor(t_game *game, t_design *design);
void		ft_walls(char **map, t_game *game);
void		ft_collects(char **map, t_game *game, t_design *design);
int			ft_free(t_game *game);

//** GAME **

void		ft_init_game(char **map, t_design *design);
void		print_map(char **map);
int			main(int argc, char **argv);
void		ft_game(t_game *game, char **map, t_design *design);
void		ft_player(char **map, t_game *game, t_design *design);
void		ft_load_enemy(char **map, t_game *game);
bool		check_exit(t_game *game, char letter);

//** CLOSE GAME **

int			free_sprites(t_game *game);


//** PLAYERS / ENEMIES **

void		load_player(t_game *game);
void		ft_put_player(t_game *game);


//** MOVEMENTS **

void		move_w(t_game *game);
void		move_s(t_game *game);
void		move_a(t_game *game);
void		move_d(t_game *game);

//** BUTTONS **

int			key_press(int key, t_game *game);
void		ft_end_game(t_game *game);

#endif
