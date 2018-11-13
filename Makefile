#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 13:28:37 by akolinko          #+#    #+#              #
#    Updated: 2018/06/08 23:12:24 by akolinko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m
WAC = \x1b[33m

SRC = main.c ft_atoi_base.c ft_map_creat.c new_window.c bresenhaim.c bonus.c check.c error.c valid.c drav.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ)  -lmlx\
    -framework OpenGl -framework AppKit -o $(NAME) -l ft -I libft -L libft

	@echo "$(OKC)FDF:\tFDF ready$(NOC)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft
	@echo "$(WAC)FDF:\tObject was created$(NOC)"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "$(ERC)FDF:\tObjects were deleted$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(ERC)FDF:\tFDF was deleted$(NOC)"

re: fclean all
