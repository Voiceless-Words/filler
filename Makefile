# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pragolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 17:11:12 by pragolan          #+#    #+#              #
#    Updated: 2018/08/10 13:42:11 by pragolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB = ./libft/libft.a

NAME = piet.filler

FLAGS =  -Wall -Wextra -Werror -I.

SRCC = ft_get_map.c ft_get_token.c ft_check_overlap.c ft_filler.c\
		ft_initialize_variables.c ft_print_cordinates.c ft_return_first.c\
		ft_squareroot.c ft_trim_rows.c ft_try_place.c ft_users_pieces.c

all: $(NAME)

$(NAME):
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(SRCC) $(LIB)

clean:
	rm -fr $(SRCO)
	make clean -C ./libft

fclean: clean
	rm -fr $(NAME)
	make fclean -C ./libft

re: fclean all
