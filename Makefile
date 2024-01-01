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
LIBS_DIR = libs
SRCS_DIR = srcs
INCS_DIR = includes
BONUS_DIR = bonus
OBJS_DIR = objs
LIBFT_DIR = $(LIBS_DIR)/libft
LIBMLX_DIR = $(LIBS_DIR)/minilibx-linux

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

define INCLUDES :=
	$(INCS_DIR)
	$(LIBFT_DIR)/includes
	$(LIBMLX_DIR)
endef
INCLUDES := $(strip $(INCLUDES))

define SRC :=
	character.c
	check_map.c
	check_maps.c
	counter.c
	destroy_mlx.c
	end_game.c
	error.c
	event_destroy.c
	event_keypress.c
	find_all_chars.c
	flood_map.c
	free_maps.c
	free_parse.c
	game.c
	init_data.c
	init_img.c
	init_imgs.c
	init_map.c
	init_mlx.c
	init_pos.c
	main.c
	message.c
	next_map.c
	put_image.c
	render_level.c
	render_tile.c
	translation.c
endef
SRC := $(strip $(SRC))

define BONUS_SRC :=
	check_map.c
	check_maps.c
	counter.c
	destroy_mlx.c
	end_game.c
	error.c
	event_destroy.c
	find_all_chars.c
	flood_map.c
	free_maps.c
	free_parse.c
	init_data.c
	init_img.c
	init_imgs.c
	init_map.c
	init_mlx.c
	init_pos.c
	message.c
	next_map.c
	put_image.c
	render_level.c
	render_tile.c
	translation.c
	$(addprefix $(BONUS_DIR)/, $(addsuffix _bonus.c, character \
	check_for_foes \
	event_keypress \
	foes \
	game \
	main \
	new_move \
	render_foes \
	wait_anim ))
endef
BONUS_SRC := $(strip $(BONUS_SRC))

OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
BONUS_OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(BONUS_SRC))

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDES_FLAGS := $(addprefix -I , $(INCLUDES))
LIB_FLAGS = --no-print-directory --silent

# Rules
.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "$(RED)! Removing$(DEFAULT) $(OBJS_DIR) files"
	@$(RM) $(OBJS_DIR)

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
	@norminette $(SRCS_DIR) $(INCS_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm OK$(DEFAULT)"}'
