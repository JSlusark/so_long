# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:49:39 by jjs               #+#    #+#              #
#    Updated: 2025/09/07 21:13:25 by jslusark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[0;31m
GRAY = \033[0;90m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
RESET = \033[0;97m

# Messages
SUCCESS = $(GREEN)Success:$(RESET)
WARNING = $(YELLOW)Warning:$(RESET)
FAILURE = $(RED)Failure:$(RESET)
IDLE = $(BLUE)Idle:$(RESET)

# Compiler flags and commands
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
REMOVE = rm -rf
UNAME := $(shell uname)

# Directories
LIBFT_DIR = code/libs/libft
PRINTF_DIR = code/libs/ft_printf
OBJ_DIR = code/obj
SRC_DIR = code/src


# Platform-specific settings
ifeq ($(UNAME), Linux)
    MLX_DIR = code/libs/minilibx-linux
    MLX_LIB = $(MLX_DIR)/libmlx.a
    EXT_LIBS = -L/usr/X11/lib -lXext -lX11 -lm -lbsd
else ifeq ($(UNAME), Darwin)
    MLX_DIR = code/libs/mlx-apple
    MLX_LIB = $(MLX_DIR)/libmlx.a
    EXT_LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Libraries
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Source files
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/error_handling/testing_functions.c \
	$(SRC_DIR)/memory_handling/allocate_data.c \
	$(SRC_DIR)/memory_handling/free_data.c \
	$(SRC_DIR)/player_interaction/close_game.c \
	$(SRC_DIR)/player_interaction/commands.c \
	$(SRC_DIR)/rendering/animation.c \
	$(SRC_DIR)/rendering/character_position.c \
	$(SRC_DIR)/rendering/render_map.c \
	$(SRC_DIR)/rendering/reload_map.c \
	$(SRC_DIR)/rendering/render_ui.c \
	$(SRC_DIR)/validate_game_data/fill_checks.c \
	$(SRC_DIR)/validate_game_data/verify_playability.c \
	$(SRC_DIR)/validate_game_data/data_collection.c \
	$(SRC_DIR)/validate_game_data/get_map.c \
	$(SRC_DIR)/validate_game_data/get_next_line.c \
	$(SRC_DIR)/validate_game_data/map_validation.c \
	$(SRC_DIR)/validate_game_data/sprite_validation.c \

# OBJ = $(SRC:.c=.o)
OBJ = $(patsubst code/%.c,$(OBJ_DIR)/%.o,$(SRC))


# Compile object files
# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: code/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


#Executable name
NAME = game

# Default target
all: $(NAME)
	@mkdir -p $(OBJ_DIR)
	@echo "$(IDLE) $(MAGENTA)$(NAME)$(RESET) is up to date!"

$(MLX_LIB):
	@make -C $(MLX_DIR) --silent

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) --silent

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) --silent

# Compile the main executable
$(NAME): $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -I. $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(EXT_LIBS) -o $(NAME)
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) archived and indexed!"

# Clean object files
clean:
	@if ls $(OBJ) >/dev/null 2>&1; then \
		$(REMOVE) $(OBJ_DIR); \
		make -C $(MLX_DIR) clean --silent; \
		make -C $(PRINTF_DIR) clean --silent; \
		make -C $(LIBFT_DIR) clean --silent; \
		echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) object files"; \
	else \
		echo "$(IDLE) object files were already cleaned"; \
	fi

# Full clean
fclean: clean
	@if [ -f $(NAME) ]; then \
		$(REMOVE) $(NAME); \
		$(REMOVE) $(PRINTF_LIB); \
		$(REMOVE) $(LIBFT_LIB); \
		make -C $(MLX_DIR) clean --silent; \
		echo "$(WARNING) removed $(MAGENTA)libftprintf.a$(RESET) library"; \
		echo "$(WARNING) removed $(MAGENTA)libft.a$(RESET) library"; \
		echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) executable"; \
	else \
		echo "$(IDLE) Executables and libraries were already cleaned"; \
	fi

# Recompile everything
re: fclean all
	@echo "$(WARNING) recompiled everything from $(MAGENTA)$(NAME)$(RESET)"

%:
	@echo "$(FAILURE) target '$@' is not a valid target.$(RESET)"
	@echo "Please use one of the following valid targets:"
	@echo "- $(GREEN)make$(RESET): compiles the project"
	@echo "- $(GREEN)make re$(RESET): recompiles the project"
	@echo "- $(GREEN)make clean$(RESET): removes object files"
	@echo "- $(GREEN)make fclean$(RESET): removes object files and the final library"

.PHONY: all clean fclean re %
