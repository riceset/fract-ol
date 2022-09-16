NAME			= fractol

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./sources/
PATH_LIBFT		= ./Libft

MINILIBX_PATH	=	./minilibx-linux/
MINILIBX		=	$(MINILIBX_PATH)libmlx.a

SRCS			= $(addprefix $(PATH_SRCS), main.c print_pixels.c)
LFLAGS			= -L $(PATH_LIBFT) -lft
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)
MLXFLAGS		= -L. -lXext -L. -lX11

all:	$(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	make -C $(MINILIBX_PATH)
	cc $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) $(MINILIBX) $(MLXFLAGS) -o $(NAME)


$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -I mlx.h -O3 -c $< -o $@

clean:
		$(RM) $(PATH_OBJS)
		make clean -C $(PATH_LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(PATH_LIBFT)

re:		fclean all

.PHONY: all clean fclean re