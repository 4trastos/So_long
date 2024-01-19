# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 12:27:32 by davgalle          #+#    #+#              #
#    Updated: 2024/01/19 21:14:09 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx -c -o -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS = src/main.c \
	   src/ft_checker.c \
	   src/ft_error.c \
	   src/so_long_utils.c \
	   src/get_next_line.c \
	   src/get_next_line_utils.c \
	   src/ft_split.c \
	   src/create_struct.c \
	   src/init_game.c \
	   src/aux_utils.c

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
