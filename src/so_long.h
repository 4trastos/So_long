/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:37:32 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/13 21:26:21 by davgalle         ###   ########.fr       */
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
char		**ft_check_map(int fd, t_design *design);
bool		ft_check_dimension();
bool		is_valid_char(char c, t_design *design);
void		ft_read_file(int fd, t_design *design, char *str);
bool		ft_check_dimension(char *line, t_design *design);

//*** errors ***

void		ft_error_msg(char *msg, char **map);

//** create new design node **

t_design	*ft_new_design(void);

//** GNL **

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *board, char *buffer);
char		*ft_strdup(char *s1);

//** auxiliars **

char		*ft_strdup(char *s1);
size_t		ft_strlen_custom(char *line);
int			ft_file_size(char *str, int size);

//** SPLIT **

char		**ft_empty_split(void);
char		*ft_strdup_custom(const char *s, size_t n);
char		**ft_free_str(char **aux);
int			ft_countc(char const *s, char c);
char		**ft_split(char const *s, char c);

#endif
