# minilibx_test
NAME		=	minilibx_test
SRCS		=	tutorial.c
OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC			=	cc
LIBX_FLAGS	=	-L../minilibx-linux -lmlx -lXext -lX11

# Rules
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re


#cc tutorial.o -L./minilibx-linux -lmlx -lXext -lX11 -o minilibx_test
