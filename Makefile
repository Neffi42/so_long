NAME = so_long
BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

INCLUDE = include/
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMLX_DIR = $(LIB_DIR)/minilibx

LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a
SRC = $(addprefix $(SRC_DIR)/, main.c)
BONUS_SRC = $(addprefix $(SRC_DIR)/$(BONUS_DIR)/, main.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "* Assembling $@"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(LIBMLX)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@
	@echo "- Compiling $<"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBMLX):
	@make -C $(LIBMLX_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)
	@echo "! Removing $(OBJ_DIR) files"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@echo "! Removing $(NAME)"
	@$(RM) $(NAME)

re: fclean all

bonus: $(LIBFT) $(LIBMLX) $(BONUS_OBJ)
	@echo "* Assembling $(BONUS)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS) $(LIBFT) $(LIBMLX)

bclean: clean
	@echo "! Removing $(BONUS)"
	@$(RM) $(BONUS)

bre: bclean bonus

norm:
	@norminette $(SRC_DIR) | awk '/Error/'

.PHONY = all clean fclean re norm bonus