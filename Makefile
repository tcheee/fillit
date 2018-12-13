# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:55:44 by tcherret          #+#    #+#              #
#    Updated: 2018/12/07 17:44:49 by tcherret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc 

FLAG = -Wall -Wextra -Werror

SRC_DIR = ./srcs/

INC_DIR = ./includes/

RM = /bin/rm -f

SRC = 	$(SRC_DIR)main.c \
	 	$(SRC_DIR)map_generator.c \
		$(SRC_DIR)solve_tet.c \
   		$(SRC_DIR)verif_take_tet.c \
		$(SRC_DIR)take_tet.c \
		$(SRC_DIR)get_size.c	

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAG) -o $@ $^ libft/libft.a -I $(INC_DIR)

%.o: %.c
	$(CC) $(FLAG) -o $@ -c $^ -I $(INC_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re
