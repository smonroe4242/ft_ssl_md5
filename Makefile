#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonroe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 00:31:44 by smonroe           #+#    #+#              #
#    Updated: 2018/11/26 00:55:59 by smonroe          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ssl

SRC = init.c input.c mdfive.c sha.c util.c utily.c main.c

LIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)

clean:
	@rm -rf a.out *~ \#*\# *.o
	@make clean -C libft

fclean: clean
	@rm $(NAME)
	@make fclean -C libft

re: fclean all

lldb:
	@gcc -g -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)

fsan:
	@gcc -g -fsanitize=address -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)