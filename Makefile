# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 11:44:09 by tkomeno           #+#    #+#              #
#    Updated: 2022/10/16 02:59:31 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

LIBFT_PATH	=	./libraries/libft
FT_PRINTF_PATH	=	./libraries/ft_printf
MLX_PATH	=	./libraries/mlx-linux

INCLUDES	=	-I includes -I $(LIBFT_PATH)/includes -I $(FT_PRINTF_PATH) -I $(MLX_PATH)

CFLAGS		=	$(INCLUDES)
# CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)

LIBS_PATH	=	-L$(LIBFT_PATH) -L$(MLX_PATH) -L$(FT_PRINTF_PATH)

LIBS		=	-lft -lftprintf -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext

MLX		=	libmlx.a libmlx_Linux.a libftprintf.a

FILES 		=	main.c

SRCS		=	$(addprefix sources/,$(FILES))

OBJS		=	$(SRCS:.c=.o)

CC		=	clang

CP		=	@cp -r

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) -C $(FT_PRINTF_PATH) --no-print-directory
	$(MAKE) -C $(MLX_PATH) --no-print-directory
	$(CC) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)

clean:
	$(RM) $(OBJS) $(MLX)
	$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) clean -C $(FT_PRINTF_PATH) --no-print-directory
	$(MAKE) clean -C $(MLX_PATH) --no-print-directory

fclean:
	$(RM) $(OBJS) $(NAME) $(MLX)
	$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) fclean -C $(FT_PRINTF_PATH) --no-print-directory
	$(MAKE) fclean -C $(MLX_PATH) --no-print-directory

re: fclean all

.PHONY: all clean fclean re
