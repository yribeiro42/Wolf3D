# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 12:49:01 by yribeiro          #+#    #+#              #
#    Updated: 2017/10/31 19:26:48 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Werror -Wextra -I. -c

FILES		= 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_strlen.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c    \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strncpy.c \
				ft_isascii.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstaddend.c \
				ft_strndup.c \
				parser.c \
				ft_printf.c \
				specifier.c \
				processes.c \
				process_int.c \
				process_string.c \
 				process_pointer.c \
 				process_octal.c \
 				process_hex.c \
 				process_unsigned.c \
 				process_switch.c \
 				process_character.c \
 				process_error.c \
 				processes2.c \
 				ft_strjoin_free.c \
 				ft_itoa_base.c \
				ft_itoa_base_u.c \
				ft_itoa_u.c \
				ft_putnstr.c \
				get_next_line.c \

OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(FILES)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re