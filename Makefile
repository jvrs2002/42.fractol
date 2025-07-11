NAME = fractol
NAME_BONUS = fractol_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
MLX_DIR = minilibx-linux/
LIBFT_DIR = libs/Libft/
FT_PRINTF_DIR = libs/ft_printf/

MLX_NAME = libmlx.a
LIBFT_NAME = libft.a
FT_PRINTF_NAME = libftprintf.a
MLX = $(MLX_DIR)/$(MLX_NAME)
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

SRC = main.c init.c mandelbrot.c utils.c hook.c window.c \
julia.c parsing.c burning_ship.c palette_1.c palette_2.c \
main_bonus.c init_bonus.c mandelbrot_bonus.c utils_bonus.c \
hook_bonus.c window_bonus.c julia_bonus.c parsing_bonus.c \
burning_ship_bonus.c palette_1_bonus.c palette_2_bonus.c

SRCS = \
	$(SRC_DIR)main.c \
	$(SRC_DIR)init.c \
	$(SRC_DIR)mandelbrot.c \
	$(SRC_DIR)utils.c \
	$(SRC_DIR)hook.c \
	$(SRC_DIR)window.c \
	$(SRC_DIR)julia.c \
	$(SRC_DIR)parsing.c \
	$(SRC_DIR)burning_ship.c \
	$(SRC_DIR)palette_1.c \
	$(SRC_DIR)palette_2.c

OBJS = \
	$(OBJ_DIR)main.o \
	$(OBJ_DIR)init.o \
	$(OBJ_DIR)mandelbrot.o \
	$(OBJ_DIR)utils.o \
	$(OBJ_DIR)hook.o \
	$(OBJ_DIR)window.o \
	$(OBJ_DIR)julia.o \
	$(OBJ_DIR)parsing.o \
	$(OBJ_DIR)burning_ship.o \
	$(OBJ_DIR)palette_1.o \
	$(OBJ_DIR)palette_2.o 

BONUS_SRCS = \
	$(SRC_DIR)main_bonus.c \
	$(SRC_DIR)init_bonus.c \
	$(SRC_DIR)mandelbrot_bonus.c \
	$(SRC_DIR)utils_bonus.c \
	$(SRC_DIR)hook_bonus.c \
	$(SRC_DIR)window_bonus.c \
	$(SRC_DIR)julia_bonus.c \
	$(SRC_DIR)parsing_bonus.c \
	$(SRC_DIR)burning_ship_bonus.c \
	$(SRC_DIR)palette_1_bonus.c \
	$(SRC_DIR)palette_2_bonus.c

BONUS_OBJS = \
	$(OBJ_DIR)main_bonus.o \
	$(OBJ_DIR)init_bonus.o \
	$(OBJ_DIR)mandelbrot_bonus.o \
	$(OBJ_DIR)utils_bonus.o \
	$(OBJ_DIR)hook_bonus.o \
	$(OBJ_DIR)window_bonus.o \
	$(OBJ_DIR)julia_bonus.o \
	$(OBJ_DIR)parsing_bonus.o \
	$(OBJ_DIR)burning_ship_bonus.o \
	$(OBJ_DIR)palette_1_bonus.o \
	$(OBJ_DIR)palette_2_bonus.o 

INC = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(MLX_DIR)

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

bonus: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME_BONUS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MiniLibX"
	@make -sC $(MLX_DIR)

$(LIBFT):
	@echo "Making Libft"
	@make -sC $(LIBFT_DIR)

$(FT_PRINTF):
	@echo "Making ft_printf"
	@make -sC $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) $(INC) -Imlx_linux -lXext -lX11 -lm -lz

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) $(INC) -Imlx_linux -lXext -lX11 -lm -lz

clean:
	@echo "Removing .o files"
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "Removing binaries"
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
