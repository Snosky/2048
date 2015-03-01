# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvelay <fvelay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/03 17:51:03 by fvelay            #+#    #+#              #
#    Updated: 2015/03/01 18:22:18 by tpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_EXE	= game_2048

SRC = 	   try.c \
		   main.c \
		   generate_grid.c \
		   is_blocked.c \
		   new_number.c \
		   show_grid.c \
		   move.c \

UNAME_S	:= $(shell uname -s)

STATIC_OBJ	= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))

HEAD_DIR	= includes
SRC_DIR		= src
STATIC_DIR	= static
LIBFT_STATIC= libft/libft.a
LIBFT_HEAD	= libft/

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
CURSE		= -lncurses

$(shell mkdir -p $(STATIC_DIR))

all: $(STATIC_EXE)

$(STATIC_EXE): $(STATIC_OBJ) $(LIBFT_STATIC)
		$(CC) -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ $(STATIC_OBJ) $(LIBFT_STATIC) $(FLAGS) $(CURSE)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT)
		$(CC) -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ -c $< $(FLAGS) $(FLAGS)

$(LIBFT_STATIC):
		make -C libft/ libft.a

.PHONY: clean fclean re

clean:
	@echo "-> Nettoyage des fichiers objet"
		make -C libft clean
			rm -f $(STATIC_OBJ)

fclean: clean
	@echo "-> Nettoyage $(STATIC_EXE)"
		make -C libft fclean
			rm -f $(STATIC_EXE)

re: fclean
		make
