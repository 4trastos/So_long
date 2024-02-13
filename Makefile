# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 12:27:32 by davgalle          #+#    #+#              #
#    Updated: 2024/02/13 15:38:22 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

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
	   src/ft_itoa.c

BONUS = bonus/main_bonus.c \
	   bonus/ft_checker_bonus.c \
	   bonus/ft_error_bonus.c \
	   bonus/so_long_utils_bonus.c \
	   bonus/get_next_line_bonus.c \
	   bonus/get_next_line_utils_bonus.c \
	   bonus/ft_split_bonus.c \
	   bonus/create_struct_bonus.c \
	   bonus/init_game_bonus.c \
	   bonus/aux_utils_bonus.c \
	   bonus/more_utils_bonus.c \
	   bonus/solvemap_bonus.c \
	   bonus/more_more_utils_bonus.c \
	   bonus/check_movements_bonus.c \
	   bonus/reset_road_bonus.c \
	   bonus/ft_radar_bonus.c \
	   bonus/sprites_bonus.c \
	   bonus/ft_player_bonus.c \
	   bonus/ft_enemy_bonus.c \
	   bonus/ft_floor_bonus.c \
	   bonus/ft_collect_bonus.c \
	   bonus/ft_animation_bonus.c \
	   bonus/ft_itoa_bonus.c

OBJTS = $(SRCS:.c=.o)

BONUS_OBJECTS = ${BONUS:.c=.o}

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJTS)
	$(CC) $(FLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJTS)

$(NAME_BONUS): ${BONUS_OBJECTS}
	$(CC) $(FLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(BONUS_OBJECTS)

clean:
	$(RM) $(OBJTS) ${BONUS_OBJECTS}

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJTS)
	$(RM) $(NAME_BONUS)
	$(RM) $(BONUS_OBJECTS)

re: all clean

.PHONY: all clean fclean re
