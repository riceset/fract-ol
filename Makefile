# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 11:44:09 by tkomeno           #+#    #+#              #
#    Updated: 2022/09/18 12:15:04 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

INCLUDES	=	-I includes -I libft/includes

CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)

LFLAGS		=	-L./libft -lft

MLXFLAGS	=	-lmlx

LIBFT		=	libft.a

FILES 		=	main.c

SRCS		=	$(addprefix sources/,$(FILES))

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(MLXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean:
	$(RM) $(OBJS) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft

.PHONY: all clean fclean re
