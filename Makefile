# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 12:09:35 by julee             #+#    #+#              #
#    Updated: 2019/01/20 20:44:21 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = @gcc -Wall -Werror -Wextra

SRC = main.c free.c env.c builtin.c process.c helper.c parse.c dir_check.c cd.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
	@cd libft && make

clean:
	@rm -f $(OBJ)
	@cd libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all
