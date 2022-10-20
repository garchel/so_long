# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:35:48 by pauvicto          #+#    #+#              #
#    Updated: 2022/10/13 21:05:15 by pauvicto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/so_long.c \
		src/check_map.c \
		src/check_possible_path.c \
		src/event_handler.c \
		src/free_handler.c \
		src/image_handler.c \
		src/movement_handler.c \
		src/gen_space.c \
		src/gen_space2.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils1.c \
		ft_printf/ft_printf_utils2.c \
		ft_printf/ft_printf_utils3.c \
		ft_printf/ft_itoa.c \
		ft_printf/ft_putchar_fd.c \
		
OBJ = $(SRCS:%.c=%.o)

CC = cc

MLX = mlx_linux/libmlx_Linux.a
LIBFT = libft/libftprintf.a

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) #-fsanitize=address

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O0 -c $< -o $@

$(MLX): $(LIBFT)
	make -C ./mlx_linux

$(LIBFT):
	${MAKE} -C ft_printf/

clean: 
	rm -rf $(OBJ)

test: $(NAME)
	valgrind ./so_long maps/map_7x7.ber
	valgrind ./so_long maps/map_7x10.ber
	valgrind ./so_long maps/map_missing_coin.ber
	valgrind ./so_long maps/map_missing_exit.ber
	valgrind ./so_long maps/map_missing_player.ber
	valgrind ./so_long maps/map_not_closed.ber
	valgrind ./so_long maps/map_not_closed2.ber
	valgrind ./so_long maps/map_not_closed3.ber
	valgrind ./so_long maps/map_not_closed4.ber
	valgrind ./so_long maps/map_not_closed5.ber
	valgrind ./so_long maps/map_not_closed6.ber
	valgrind ./so_long maps/map_not_closed7.ber
	valgrind ./so_long maps/map_not_closed8.ber
	valgrind ./so_long maps/map_not_rectan.ber
	valgrind ./so_long maps/map_not_rectan2.ber
	valgrind ./so_long maps/map.ber

fclean: clean
	rm -rf $(NAME)

all: $(NAME) 
	
re: fclean
	make all
	
.PHONY: clean fclean all re 