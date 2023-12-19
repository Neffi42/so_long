# Program name
NAME = so_long

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

# Directories
LIB_DIR = lib
SRC_DIR = src
INC_DIR = include
BONUS_DIR = bonus
OBJ_DIR = obj
LIBFT_DIR = lib/libft
LIBMLX_DIR = lib/minilibx

# Files
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

define LIB :=
	$(LIBFT)
	$(LIBMLX)
	-lX11
	-lXext
endef
LIB := $(strip $(LIB))

define INCLUDE :=
	$(INC_DIR)
	$(LIBFT_DIR)/include
	$(LIBMLX_DIR)
endef
INCLUDE := $(strip $(INCLUDE))

define SRC :=
	main.c
	message.c
	end_game.c
	free_maps.c
	check_maps.c
	check_map.c
	flood_map.c
	find_all_chars.c
	init_pos.c
	init_map.c
	init_mlx.c
	init_img.c
	init_imgs.c
	init_data.c
	event_keypress.c
	event_destroy.c
	put_image.c
	translation.c
	render_level.c
	render_tile.c
	render_counter.c
	character.c
	game.c
endef
SRC := $(strip $(SRC))

define BONUS_SRC :=
	message.c
	end_game.c
	free_maps.c
	check_maps.c
	check_map.c
	flood_map.c
	find_all_chars.c
	init_pos.c
	init_map.c
	init_mlx.c
	init_img.c
	init_imgs.c
	init_data.c
	event_keypress.c
	event_destroy.c
	put_image.c
	translation.c
	render_level.c
	render_tile.c
	render_counter.c
	$(addprefix $(BONUS_DIR)/, $(addsuffix _bonus.c, main \
	foes \
	render_foes \
	game \
	character))
endef
BONUS_SRC := $(strip $(BONUS_SRC))

OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
BONUS_OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDE_FLAGS := $(addprefix -I , $(INCLUDE))
LIB_FLAGS = --no-print-directory --silent

# Rules
.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJ_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "$(RED)! Removing$(DEFAULT) $(OBJ_DIR) files"
	@$(RM) $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)

.PHONY: re
re: fclean all

$(LIBFT):
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

$(LIBMLX):
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(GREEN)* Assembling $(BWHITE)libmlx_Linux.a$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: cleanlib
cleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make clean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make clean -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: fcleanlib
fcleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make clean -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

.PHONY: relib
relib: fcleanlib $(LIBFT) $(LIBMLX)

.PHONY: bonus
bonus: $(LIBFT) $(LIBMLX) $(BONUS_OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(NAME)

.PHONY: norm
norm:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make -C $(LIBFT_DIR) norm $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"
	@norminette $(SRC_DIR) $(INC_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm OK$(DEFAULT)"}'
