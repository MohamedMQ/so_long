# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 11:11:36 by mmaqbour          #+#    #+#              #
#    Updated: 2023/04/08 11:34:31 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDATORY = so_long

SRC = all_img_con.c check_map.c check_path.c ft_check_and_display.c ft_display.c \
	so_long.c so_long_utils.c utils_functions/check_map_2.c utils_functions/check_path_2.c \
	utils_functions/ft_check_and_display_2.c utils_functions/get_next_line.c \
	utils_functions/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_putadres.c \
	ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_uns.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME_MANDATORY)

$(NAME_MANDATORY): $(OBJ) so_long.h
	cc $(OBJ) -Wall -Wextra -Werror -g -lmlx -framework OpenGL -framework AppKit -o $(NAME_MANDATORY)

clean:
	rm -rf *.o utils_functions/*.o ft_printf/*.o

fclean: clean
	rm -rf $(NAME_MANDATORY)

re: fclean all
.PHONY: all clean fclean re
