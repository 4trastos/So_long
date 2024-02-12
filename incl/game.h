/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/12 21:02:47 by davgalle         ###   ########.fr       */
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

typedef struct	s_game
{
	int				width;
	int				height;
	int				collect_count;
	int				moves;
	int				postcontrol;
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
	void			*playerA;
	void			*playerB;
	void			*playerup;
	void			*playerupA;
	void			*playerupB;
	void			*playerdown;
	void			*playerdownA;
	void			*playerdownB;
	void			*playeright;
	void			*playerightA;
	void			*playerightB;
	void			*collect;
	void			*enemys;
	char			**map;
	char			**floor;
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
char		*ft_itoa(int n);

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
void		ft_moveup(t_game *game);
void		ft_movedown(t_game *game);
void		ft_moveright(t_game *game);
void		ft_moveleft(t_game *game);

//** BUTTONS **

int			key_press(int key, t_game *game);
void		ft_win_game(t_game *game);
void		ft_putmoves(int c);

#endif
