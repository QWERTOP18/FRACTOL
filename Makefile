CFLAGS     := -Werror -Wall -Wextra
DFLAGS     := 
LFLAGS     := #-lXext -lX11 -lm -lbsd

SRCS       := main.c system_exit.c system_init.c





NAME := fractol
CC := cc
MLX_PATH   := ./minilibx-linux
# MLX        := -L$(MLX_PATH) -lmlx

LIBFT_DIR  := libft
LIBFT 	   := libft/libft.a


INCDIR     :=  $(LIBFT) $(MLX)

all: $(NAME)

%.o: %.c


$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	make -C $(MLX_PATH)

-include $(DEPS)
$(NAME): $(MLX_PATH) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIB) -I$(INCLIB) $(LFLAGS)

clean:
	


fclean: clean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
