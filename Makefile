# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/13 16:14:59 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/31 19:44:53 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
SRC = 
MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	gcc $(FLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $^ -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	
clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
