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

NAME_BONUS = so_long_bnus

SRC = all_img_con.c check_map.c check_path.c ft_check_and_display.c ft_display.c \
	so_long.c so_long_utils.c utils_functions/check_map_2.c utils_functions/check_path_2.c \
	utils_functions/ft_check_and_display_2.c utils_functions/get_next_line.c \
	utils_functions/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_putadres.c \
	ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_uns.c \
	ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

OBJ = $(SRC:.c=.o)

SRC_BNUS = so_long_bonus/all_img_con_bonus.c so_long_bonus/so_long_utils_bonus.c \
	so_long_bonus/check_map_bonus.c so_long_bonus/check_path_bonus.c so_long_bonus/ft_check_and_display_bonus.c \
	so_long_bonus/ft_display_bonus.c so_long_bonus/so_long_bonus.c so_long_bonus/all_move_and_animation_bonus.c \
	so_long_bonus/utils_functions/check_map_2_bonus.c so_long_bonus/utils_functions/check_path_2_bonus.c \
	so_long_bonus/utils_functions/ft_display_bonus_2.c so_long_bonus/utils_functions/ft_check_and_display_2_bonus.c \
	so_long_bonus/utils_functions/ft_check_and_display_3_bonus.c so_long_bonus/utils_functions/ft_itoa_bonus.c \
	so_long_bonus/utils_functions/get_next_line_bonus.c so_long_bonus/utils_functions/get_next_line_utils_bonus.c \
	so_long_bonus/utils_functions/all_move_and_animation_2_bonus.c ft_printf/ft_printf.c ft_printf/ft_putadres.c \
	ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_uns.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

OBJ_BONUS = $(SRC_BNUS:.c=.o)

%.o: %.c 
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME_MANDATORY)

$(NAME_MANDATORY): $(OBJ) so_long.h
	cc $(OBJ) -Wall -Wextra -Werror -g -lmlx -framework OpenGL -framework AppKit -o $(NAME_MANDATORY)

bonus: $(OBJ_BONUS) so_long_bonus/so_long_bonus.h
	cc	$(OBJ_BONUS) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	rm -rf *.o utils_functions/*.o ft_printf/*.o so_long_bonus/*.o so_long_bonus/utils_functions/*.o

fclean: clean
	rm -rf $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all
.PHONY: all clean fclean re bonus
