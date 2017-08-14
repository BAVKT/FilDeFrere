# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 06:27:28 by vmercadi          #+#    #+#              #
#    Updated: 2017/08/14 21:34:00 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/fdf.c srcs/error.c srcs/display.c srcs/init.c srcs/utils.c \
		srcs/check.c

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

MFLAGS = -framework OpenGL -framework AppKit -L $(MLX) -lmlx

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

MLX = autre/minilibx_macos/

.PHONY: all re clean

all: $(NAME)

$(NAME):$(SRCO)
	@make -C libft/
	@gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC) $(MFLAGS) -I $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

ultra: all clean

re: fclean all
