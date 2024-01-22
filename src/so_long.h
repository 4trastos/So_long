/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:37:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/22 17:43:07 by davgalle         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct	s_error {
	char	wall;
	char	space;
	char	exit;
	char	player;
	char	enemys;
	char	collect;

}				t_error;

typedef struct	s_design {
	int		wall;
	int		space;
	int		exit;
	int		player;
	int		enemys;
	int		collect;
	size_t	yp;
	size_t	xp;
	size_t	yc;
	size_t	xc;
	size_t	ye;
	size_t	xe;

}				t_design;

typedef struct	s_game {

}	t_game;

//*** check map ***

char		**ft_check_arg(int argc, char **argv, t_design *design, char **map);
int			ft_strnrcmp(char *argv, char *str, int count);
char		**ft_check_map(int fd, t_design *design, char **map);
bool		ft_check_dimension();
bool		is_valid_char(char c, t_error *error);
char		*ft_read_file(int fd, t_error *error, char *str, t_design *design);
bool		ft_check_dimension(char *line, t_error *error, size_t file_size);
bool		ft_feasible_map(char **map, t_design *design);
bool		ft_check_border(char **map);
bool		ft_middle_map(char *str, t_design *design);
bool		ft_restmap(char *str, t_design *design);
bool		ft_singleline(char **map, size_t boxes);
bool		ft_multiplelines(char **map, size_t play_lines, size_t boxes, t_design *design);
bool		ft_solvemap(char **map, t_design *design);

//*** errors ***

void		ft_error_msg(char *msg, char **map);
void		ft_error_map(char *msg, char *line);
void		ft_freemap(char *msg, char **map);

//** create new design node **

t_design	*ft_new_design(void);
t_error		*ft_new_error(void);
bool		ft_completemap(char *str, t_design *design);

//** get next line **

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *board, char *buffer);
char		*ft_strdup(char *s1);

//** auxiliars **

char		*ft_strdup(char *s1);
size_t		ft_strlen_custom(char *line);
void		ft_file_size(char *line, size_t *size);
char		**ft_free_map(char **map);
bool		ft_getY(char **map, int c);
bool		ft_getX(char **map, int c);
size_t		ft_playlines(char **map);
size_t		ft_countboxes(char **map);
bool		ft_ifpow(char **map, t_design *design);

//** SPLIT **

char		**ft_empty_split(void);
char		*ft_strdup_custom(const char *s, size_t n);
char		**ft_free_str(char **aux);
int			ft_countc(char const *s, char c);
char		**ft_split(char const *s, char c);

//** GAME **

void		ft_init_game(char **map, t_design *design);
void		print_map(char **map);
#endif
