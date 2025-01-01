CFLAGS      := -Werror -Wall #-Wextra

SRCS        := main.c system.c
OBJS        := $(SRCS:.c=.o)

NAME        := fractol
CC          := cc 


MLX			:= $(MLX_DIR)/libmlx.a
MLX_DIR     := minilibx-linux
LIBFT_DIR   := libft
LIBFT       := libft/libft.a
IFLAGS      := -I$(LIBFT_DIR) -I$(MLX_DIR)
LFLAGS      := -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) $(LIBFT) -o $@

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	@echo "Cloning minilibx-linux..."
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(LIBFT): | $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
