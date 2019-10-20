# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:57:28 by xlongfel          #+#    #+#              #
#    Updated: 2019/10/19 16:05:39 by ggeri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = fillit

# compiling with such flags
FLAGS = -Wall -Wextra -Werror

# functions name
SRC = main solution array

# functions .c
FUNC_C = $(patsubst %, %.c, $(SRC))

# object files
OBJ = $(patsubst %, %.o, $(SRC))

# header
HEADER = fillit.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -I libft -I $(HEADER) -o main.o -c main.c
	gcc -o $(NAME) $(OBJ) -I $(HEADER) -I libft -L libft/ -lft

$(FUNC_O): %.o: %.c
	gcc $(FLAGS) -c $< -I $(HEADERS)

clean:
		make -C libft/ clean 
		rm -rf $(OBJ)

fclean: clean
		rm -rf libft/libft.a
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
