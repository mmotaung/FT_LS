# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 11:16:32 by mmotaung          #+#    #+#              #
#    Updated: 2019/09/02 17:55:56 by mmotaung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_ls.c print_ls.c file_check.c list.c permissions.c sort_list.c

FLAGS = gcc -Wall -Wextra -Werror -o

all : $(NAME)

$(NAME):
		@echo "Compiling $(NAME)..."
		@make -C libft/
		@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes
clean:
	@rm -rf $(NAME)

fclean:
	@echo "Cleaning..."
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all
