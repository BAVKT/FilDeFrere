# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 06:27:28 by vmercadi          #+#    #+#              #
#    Updated: 2016/12/20 22:41:28 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = visuel.c

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft
	clang -Wall -Wextra -Werror -I libft/includes -o TEST.o -c TEST.c
#	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) TEST.o -lmlx -framework OpenGL -framework AppKit -I libft/includes -L libft/ -lft

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
