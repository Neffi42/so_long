# Program name
NAME = so_long
BONUS = so_long_bonus

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIB_FLAGS = --no-print-directory --silent

# Directories
INCLUDE = include/
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMLX_DIR = $(LIB_DIR)/minilibx

# Files
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a
MLX_LIBS = -lX11 -lXext
SRC = $(addprefix $(SRC_DIR)/, main.c error.c end_game.c \
		free_maps.c check_maps.c check_map.c flood_map.c \
		find_all_chars.c init_pos.c init_map.c init_mlx.c \
		event_keypress.c event_destroy.c)
BONUS_SRC = $(addprefix $(SRC_DIR)/$(BONUS_DIR)/, main.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(LIBMLX) $(MLX_LIBS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(BONUS_DIR)
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)

$(LIBMLX):
	@echo "$(GREEN)* Assembling $(BWHITE)libmlx_Linux.a$(DEFAULT)"
	@make -C $(LIBMLX_DIR) $(LIB_FLAGS)

clean:
	@make clean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@make clean -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(RED)! Removing$(DEFAULT) $(OBJ_DIR) files"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)

re: fclean all

bonus: $(LIBFT) $(LIBMLX) $(BONUS_OBJ)
	@echo "* Assembling $(BONUS)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS) $(LIBFT) $(LIBMLX)

bclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(BONUS)"
	@$(RM) $(BONUS)

bre: bclean bonus

norm:
	@norminette $(SRC_DIR) | awk '/Error/'
	@norminette $(INCLUDE) | awk '/Error/'
.PHONY = all clean fclean re norm bonus