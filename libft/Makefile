# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 11:06:07 by mmotaung          #+#    #+#              #
#    Updated: 2019/09/02 17:52:34 by mmotaung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I includes

SRC = ft_strlen.c ft_strcmp.c \
	  ft_memcpy.c ft_strnew.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_strjoin.c ft_itoa.c  ft_strcpy.c ft_memset.c ft_memalloc.c ft_bzero.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
