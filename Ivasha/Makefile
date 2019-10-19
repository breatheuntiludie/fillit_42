# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 19:23:35 by ggeri             #+#    #+#              #
#    Updated: 2019/10/17 19:57:56 by ggeri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = fillit

# compiling with such flags
FLAGS = -Wall -Wextra -Werror

# functions name without .c
FUNC = processing visualisation

# adding 2 functions ".c"
FUNC_C = $(patsubst %, %.c, $(FUNC))

# headers
HEADERS = fillit.h

# object files .o
FUNC_O = $(patsubst %, %.o, $(FUNC))

all: $(NAME)

$(NAME): $(FUNC_O) $(HEADERS)
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) -I libft -I $(HEADERS) -o main.o -c main.c
	clang -o $(NAME) main.o $(FUNC_O) -I $(HEADERS) -I libft -L libft/ -lft

$(FUNC_O): %.o: %.c
	gcc $(FLAGS) -c $< -I $(HEADERS)

clean:
	rm -f $(FUNC_O) main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
