# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:57:28 by xlongfel          #+#    #+#              #
#    Updated: 2019/10/17 13:46:09 by xlongfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./main.c ./solution.c ./ft_memalloc.c ./ft_strlen.c ./ft_memset.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_strnew.c ./ft_strncpy.c 
OBJ = $(SRC:.c=.o)
INCLUDE = ./includes
LIBFT = libft/libft.a
HEADER = ./fillit.h
.PHONY: all clean fclean re
all: $(NAME)
%.o:%.c
	gcc -Wall -Wextra -Werror -I./$(INCLUDE) -o $@ -c $<
$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I$(INCLUDE)
clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
