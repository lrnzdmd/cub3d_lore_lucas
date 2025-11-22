# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 20:22:59 by lde-medi          #+#    #+#              #
#    Updated: 2025/11/22 05:47:39 by lde-medi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -g3 -O3 -Wall -Wextra -Werror -Iincludes -std=gnu99 -Ilibft/includes -Imlx/ #-fsanitize=address
SRCS = 	srcs/main.c \
		srcs/cleanup/cleanup.c \
		srcs/cleanup/exit.c \
		srcs/game/enemy.c \
		srcs/game/enemy_anim.c \
		srcs/gfx/render_minimap.c \
		srcs/gfx/render_world.c \
		srcs/gfx/shapes.c \
		srcs/gfx/shapes_utils.c \
		srcs/init/init_enemy.c \
		srcs/init/init_gfx.c \
		srcs/init/init_map.c \
		srcs/init/init_player.c \
		srcs/input/action.c \
		srcs/input/input.c \
		srcs/input/movement.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing_args.c \
		srcs/parsing/parsing_doors.c \
		srcs/parsing/parsing_files.c \
		srcs/parsing/parsing_map.c \
		srcs/safe_ops/safe_alloc.c \
		srcs/safe_ops/safe_mlx_ops.c \
		srcs/utils/gfx_utils.c \
		srcs/utils/math_utils.c \
		srcs/utils/parse_utils.c \
		srcs/utils/time_utils.c
OBJS = $(SRCS:.c=.o)
LIBS = libft/libft.a mlx/libmlx_Linux.a -lX11 -lXext -lm

GREEN = \033[0;32m
DEFAULT = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --silent
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean --silent
	@echo -e "$(GREEN)$(NAME) obj files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean --silent
	@echo -e "$(GREEN)$(NAME) all files deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
