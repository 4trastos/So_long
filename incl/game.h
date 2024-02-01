/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 20:24:43 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define SIZE 64

void	window(void);

//** STRUCT MLX **

typedef struct	s_data
{
	void	*mlx;
	void	*img;
	void	*grass;
	void	*imgtwo;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	char	*addr;            //añadir resolucion
	int		bits_per_pixel;   //bits or pixel
	int		line_length;
	int		endian;           //el orden de los bites
}				t_data;


typedef struct	s_sprite
{
	void		*wall;
	void		*grass;
	void		*exit;
	void		*player;
	void		*collect;
	void		*enemys;
}				t_sprite;

typedef struct	s_game
{
	int			width;
	int			height;
	int			collect;
	void		*mlx;
	void		*new_w;
	t_design	*design;
	t_sprite	sprites;
	char		**map;
	char		**floor;
}				t_game;


//** WINDOW **

void		ft_window(char **map, t_design *design);
void		*mlx_init();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_sprite	ft_load_sprites(t_game *game);


//** GAME **

void		ft_init_game(char **map, t_design *design);
void		print_map(char **map);
int			main(int argc, char **argv);
void		ft_game(t_game *game, char **map, t_design *design);
void		ft_playerlist(char **map, t_game *game);
void		ft_enemy_mov(t_game *game);

//** CLOSE GAME **

int			free_sprites(t_game *game);

#endif
