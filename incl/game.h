/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/31 20:25:18 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

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
	char	*addr;            //añadir resolucion
	int		bits_per_pixel;   //bits or pixel
	int		line_length;
	int		endian;           //el orden de los bites
}				t_data;

typedef struct	s_game
{
	int			width;
	int			height;
	void		*mlx;
	void		*new_w;
	t_design	*design;
	char		**map;
	char		**floor;
}				t_game;

//** WINDOW **

void		ft_window(char **map);
void		*mlx_init();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

//** GAME **

void		ft_init_game(char **map, t_design *design);
void		print_map(char **map);
int			main(int argc, char **argv);

/*
typedef struct s_game
{
	int			width;
	int			height;
	void		*id;
	void		*w_id;
	t_design	*lay;
	t_design	lay_bak;
	t_sprite	sprites;
	t_player	*pl;
	t_player	*gh;
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			pac_dying;
	int			panic_mode;
	int			n_frames;
	int			n_moves;
	int			redraw;
	int			g_rate;
}				t_game;
*/
#endif
