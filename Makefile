# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:49:39 by jjs               #+#    #+#              #
#    Updated: 2024/12/30 20:11:33 by jslusark         ###   ########.fr        #
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
LIBFT_DIR = code/libft
PRINTF_DIR = code/ft_printf

# Platform-specific settings
ifeq ($(UNAME), Linux)
    MLX_DIR = code/minilibx-linux
    MLX_LIB = $(MLX_DIR)/libmlx.a
    EXT_LIBS = -L/usr/X11/lib -lXext -lX11 -lm -lbsd
else ifeq ($(UNAME), Darwin)
    MLX_DIR = code/mlx-apple
    MLX_LIB = $(MLX_DIR)/libmlx.a
    EXT_LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Libraries
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Source files
SRC = code/src/main.c \
	code/src/map_data/data_collection.c \
	code/src/map_data/get_map.c \
	code/src/map_data/get_next_line.c \
	code/src/map_data/map_validation.c \
	code/src/sprite_data/sprite_validation.c \
	code/src/sprite_data/get_chara_position.c \
	code/src/rendering/render_map.c \
	code/src/rendering/verify_playability.c \
	code/src/rendering/fill_checks.c \
	code/src/player_interaction/commands.c \
	code/src/player_interaction/close_game.c \
	code/src/memory_handling/freeing_functions.c \
	code/src/memory_handling/allocation_functions.c \
	code/src/rendering/animation.c \
	code/src/error_handling/testing_functions.c

OBJ = $(SRC:.c=.o)

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

#Executable name
NAME = game

# Default target
all: $(NAME)
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
		$(REMOVE) $(OBJ); \
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
