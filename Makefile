# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 11:44:09 by tkomeno           #+#    #+#              #
#    Updated: 2022/09/19 18:46:21 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

LIBFT_PATH	=	./libraries/libft
MLX_PATH	=	./libraries/mlx

INCLUDES	=	-I includes -I $(LIBFT_PATH)/includes

CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)

LIBS_PATH	=	-L$(LIBFT_PATH) -L$(MLX_PATH)

LIBS		=	-lft -lmlx42

LIBFT		=	libft.a
MLX			=	libmlx42.dylib

FILES 		=	image.c

SRCS		=	$(addprefix sources/,$(FILES))

OBJS		=	$(SRCS:.c=.o)

CP			=	@cp -r

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CP) $(MLX_PATH)/$(MLX) .
	$(CC) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)

clean:
	$(RM) $(OBJS) $(MLX)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)

fclean:
	$(RM) $(OBJS) $(NAME) $(MLX)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(MLX_PATH)

re: fclean all

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

.PHONY: all clean fclean re
