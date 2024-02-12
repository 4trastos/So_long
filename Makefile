# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: usuario <usuario@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 12:27:32 by davgalle          #+#    #+#              #
#    Updated: 2024/02/12 18:25:35 by usuario          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx -c -o -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

LINKS = -I /usr/local/include -L /usr/local/lib \
    -l mlx -l ft -framework OpenGL -framework Appkit

SRCS = src/main.c \
	   src/ft_checker.c \
	   src/ft_error.c \
	   src/so_long_utils.c \
	   src/get_next_line.c \
	   src/get_next_line_utils.c \
	   src/ft_split.c \
	   src/create_struct.c \
	   src/init_game.c \
	   src/aux_utils.c \
	   src/more_utils.c \
	   src/solvemap.c \
	   src/more_more_utils.c \
	   src/check_movements.c \
	   src/reset_road.c \
	   src/ft_radar.c \
	   src/sprites.c \
	   src/ft_player.c \
	   src/ft_enemy.c \
	   src/ft_floor.c \
	   src/ft_collect.c \
	   src/ft_animation.c \
	   src/check_exit.c

OBJTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(FLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJTS)

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJTS)

re: all clean

.PHONY: all clean fclean re
