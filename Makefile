# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblesche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 10:25:45 by cblesche          #+#    #+#              #
#    Updated: 2017/11/02 06:40:18 by cblesche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
INCLUDES = includes
FLAGS = -Wall -Werror -Wextra
SRCS = wolf.c draw.c raycast.c mlx.c key_handler.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : $(SRCSREP)/%.c
	$(CC) $(FLAGS) -I$(INCLUDES) -Ilibft -c $?
$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(FLAG) -I$(INCLUDES) $^ -lmlx -Llibft -lft -framework OpenGl -framework Appkit -o $@
clean :
	make clean -C libft
	rm -f $(OBJS)
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
re : fclean all
