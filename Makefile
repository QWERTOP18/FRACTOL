CFLAGS      := -Werror -Wall -Wextra -O2
DFLAGS      := 






SRCS        := main.c system.c hook_handler.c hook_utils.c calculate.c color.c render.c
 
OBJS        := $(SRCS:.c=.o)

NAME        := fractol
CC          := cc 
VALGRIND    := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q

MLX_DIR     := minilibx-linux
MLX			:= $(MLX_DIR)/libmlx.a
LIBFT_DIR   := libft
LIBFT       := libft/libft.a
IFLAGS      := -I$(LIBFT_DIR) -I$(MLX_DIR)
LFLAGS      := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME) 



$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $@



%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@
	


$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)


$(LIBFT): | $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

mandelbrot:
	$(VALGRIND) ./fractol mandelbrot

julia:
	$(VALGRIND) ./fractol julia

mlx:
	@echo "Cloning minilibx-linux..."
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

libft:
	@echo "Cloning libft..."
    



re: fclean all

.PHONY: all clean fclean re
