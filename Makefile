# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 22:12:47 by cmakario          #+#    #+#              #
#    Updated: 2023/11/16 19:34:36 by cmakario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FUNCTIONS = ft_printf.c \
			ft_printf_help_functions.c \

OBJ_FILES = $(FUNCTIONS:%.c=%.o)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)
# ar : packs .o files into a single one and later i can link a file

$(OBJ_FILES) : $(FUNCTIONS)
	$(CC) $(CFLAGS) -c $(FUNCTIONS)

all: $(NAME)

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re