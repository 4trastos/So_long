/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:51:47 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 16:03:00 by davgalle         ###   ########.fr       */
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
	char	*addr;            //añadir resolucion
	int		bits_per_pixel;   //bits or pixel
	int		line_length;
	int		endian;           //el orden de los bites
}				t_data;

typedef struct	s_game
{
	int			width;
	int			height;
	int			collect;
	void		*mlx;
	void		*new_w;
	t_design	*design;
	char		**map;
	char		**floor;
}				t_game;

//** WINDOW **

void		ft_window(char **map, t_design *design);
void		*mlx_init();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

//** GAME **

void		ft_init_game(char **map, t_design *design);
void		print_map(char **map);
int			main(int argc, char **argv);
void		ft_game(t_game *game, char **map, t_design *design);

#endif
