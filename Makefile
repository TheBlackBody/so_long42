# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 10:25:14 by sfernand          #+#    #+#              #
#    Updated: 2023/01/31 09:34:20 by sfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = main \
		windows \
		image \
		background

GNL_FILE = get_next_line \
			get_next_line_utils

PRINTF_PATH = ./printf/
PRINTF_FILE = libftprintf.a

LIBFT_PATH = ./Libft1/
LIBFT_FILE = libft.a

MLX_PATH = ./mlx/
MLX_FILE = libmlx.a

FTPRINTF_PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_MLX = $(addprefix $(MLX_PATH), $(MLX_FILE))

GNL_DIR = ./get_next_line/
GNL = $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILE)))

OBJS_GNL_DIR = ./get_next_line/
OBJS_GNL = $(addprefix $(OBJS_GNL_DIR), $(addsuffix .o, $(GNL_FILE)))

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS), $(GNL)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 -c -o $@ $<

$(NAME): $(OBJS) $(OBJS_GNL)
	make -sC $(LIBFT_PATH)
	make -sC $(PRINTF_PATH)
	make -sC $(MLX_PATH)
	gcc $(CFLAGS) $(OBJS) $(OBJS_GNL) $(LIBFT_LIB) $(FTPRINTF_PRINTF) $(MLX_MLX) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)

ft_printf:
	make -sC $(PRINTF_PATH)

lib: 
	@make -sC $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_GNL)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(PRINTF_PATH)
	@make clean -sC $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -sC $(LIBFT_PATH)
	make fclean -sC $(PRINTF_PATH)
	make fclean -sC $(MLX_PATH)
	
re: clean all
