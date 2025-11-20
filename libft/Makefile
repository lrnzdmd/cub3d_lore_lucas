# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 18:59:10 by lde-medi          #+#    #+#              #
#    Updated: 2025/11/13 04:44:21 by lde-medi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -O3 -g3
NAME = libft.a
SRCS =	char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_isprint.c \
		char/ft_isspace.c \
		char/ft_tolower.c \
		char/ft_toupper.c \
		conv/ft_atoi.c \
		conv/ft_itoa.c \
		gnl/ft_get_next_line.c \
		io/ft_dprintf.c \
		io/ft_sprintf.c \
		io/ft_printf.c \
		io/ft_putchar_fd.c \
		io/ft_putendl_fd.c \
		io/ft_putnbr_fd.c \
		io/ft_putstr_fd.c \
		io/ft_vdprintf.c \
		io/ft_vdprintf_utils.c \
		io/ft_vdprintf_utils_more.c \
		list/ft_lstadd_back.c \
		list/ft_lstadd_front.c \
		list/ft_lstclear.c \
		list/ft_lstdelone.c \
		list/ft_lstiter.c \
		list/ft_lstlast.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \
		list/ft_lstsize.c \
		math/ft_clamp.c \
		math/ft_sqrt.c \
		math/v2i/ft_v2i.c \
		math/v2i/ft_v2i_ops.c \
		math/v2d/ft_v2d.c \
		math/v2d/ft_v2d_ops.c \
		math/vector_utils/ft_vector_utils.c \
		memory/ft_bzero.c \
		memory/ft_calloc.c \
		memory/ft_multifree.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memset.c \
		memory/ft_realloc.c \
		misc/ft_ternop.c \
		misc/ft_arr_len.c \
		string/ft_join_n_str.c \
		string/ft_split.c \
		string/ft_strchcount.c \
		string/ft_strchr.c \
		string/ft_strcmp.c \
		string/ft_strdup.c \
		string/ft_striteri.c \
		string/ft_strjoin.c \
		string/ft_strlcat.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strmapi.c \
		string/ft_strncmp.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strtok.c \
		string/ft_strtrim.c \
		string/ft_substr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $?

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

