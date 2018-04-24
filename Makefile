# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adondera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 15:27:49 by adondera          #+#    #+#              #
#    Updated: 2018/02/24 15:45:46 by adondera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Werror -Wall -Wextra
SRC		= *.c
OBJ		= *.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $(FLAGS) -I. -c $(SRC)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
