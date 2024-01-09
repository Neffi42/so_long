# Program name
NAME = libft.a

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
SRCS_DIR = srcs
OBJS_DIR = objs

# Files
define INCLUDES :=
	includes
endef
INCLUDES := $(strip $(INCLUDES))

define SRCS :=
	ft_atoi.c
	ft_atol.c
	ft_bzero.c
	ft_calloc.c
	ft_count_char.c
	ft_count_words.c
	ft_dlstadd_back.c
	ft_dlstadd_front.c
	ft_dlstclear.c
	ft_dlstdelone.c
	ft_dlstiter.c
	ft_dlstlast.c
	ft_dlstmap.c
	ft_dlstnew.c
	ft_dlstsize.c
	ft_dprintf.c
	ft_dprintf_utils.c
	ft_freejoin.c
	ft_free_tab.c
	ft_get_next_line.c
	ft_isalnum.c
	ft_isalpha.c
	ft_isascii.c
	ft_isdigit.c
	ft_isprint.c
	ft_itoa.c
	ft_lstadd_back.c
	ft_lstadd_front.c
	ft_lstclear.c
	ft_lstdelone.c
	ft_lstiter.c
	ft_lstlast.c
	ft_lstmap.c
	ft_lstnew.c
	ft_lstsize.c
	ft_memchr.c
	ft_memcmp.c
	ft_memcpy.c
	ft_memmove.c
	ft_memset.c
	ft_nbrlen.c
	ft_printf.c
	ft_putchar_fd.c
	ft_putendl_fd.c
	ft_putnbr_base_fd.c
	ft_putnbr_fd.c
	ft_putstr_fd.c
	ft_putun_nbr_base_fd.c
	ft_quicksort_int_tab.c
	ft_rand.c
	ft_range_rand.c
	ft_split.c
	ft_strchr.c
	ft_strdup.c
	ft_striteri.c
	ft_strjoin.c
	ft_strlcat.c
	ft_strlcpy.c
	ft_strlen.c
	ft_strmapi.c
	ft_strncmp.c
	ft_strnstr.c
	ft_strrchr.c
	ft_strtrim.c
	ft_substr.c
	ft_tolower.c
	ft_toupper.c
endef
SRCS := $(strip $(SRCS))

OBJS := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDE_FLAGS := $(addprefix -I , $(INCLUDES))

# Rules
.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@ar rcs $@ $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

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

.PHONY: norm
norm:
	@norminette $(SRCS_DIR) include | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm OK$(DEFAULT)"}'
