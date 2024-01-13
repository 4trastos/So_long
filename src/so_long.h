/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:37:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 15:02:04 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_design {
	char	wall;
	char	space;
	char	exit;
	char	player;
	char	enemys;
	char	collect;

}				t_design;

typedef struct	s_game {

}	t_game;

//*** check map ***

char		**ft_check_arg(int argc, char **argv, t_design *design);
int			ft_strnrcmp(char *argv, char *str, int count);
int			ft_strlen(char *str);
char		**ft_check_map(int fd, t_design *design);
bool		ft_cheack_dimension();

//*** errors ***

void		ft_error_msg(char *msg, char **map_str);
t_design	ft_newmap_error(void);

//** create new design node **

t_design	ft_new_design(void);

#endif
