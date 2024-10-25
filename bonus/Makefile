# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:49:39 by jjs               #+#    #+#              #
#    Updated: 2024/10/25 21:44:47 by jslusark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[0;31m
GRAY = \033[0;90m
RED = \033[0;91m
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

# Directories
MLX_DIR = mlx
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

# Libraries
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
EXT_LIBS = -L/usr/X11/lib -lXext -lX11 -lm -lbsd #for linux
# EXT_LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKi #for mac

# Source files
SRC = main.c \
	src/map_data/data_collection.c \
	src/map_data/get_map.c \
	src/map_data/get_next_line.c \
	src/map_data/map_validation.c \
	src/sprite_data/sprite_validation.c \
	src/sprite_data/get_chara_position.c \
	src/rendering/render_map.c \
	src/rendering/verify_playability.c \
	src/player_interaction/commands.c \
	src/memory_handling/freeing_functions.c \
	src/memory_handling/allocation_functions.c \
	src/error_handling/testing_functions.c

OBJ = $(SRC:.c=.o)

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

#Executable name
NAME = so_long_bonus

# Default target
all: $(NAME)
	@echo "$(IDLE) $(MAGENTA)$(NAME)$(RESET) is up to date!"
$(MLX_LIB):
	@make -C $(MLX_DIR) --silent
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) --silent
$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) --silent

# later add also compilation for libft, printf and getnextline
$(NAME): $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -I. $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(EXT_LIBS) -o $(NAME)
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) archived and indexed!"

# added if statements so that itwill clean only when th o files are present
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

# added if statements so that itwill clean only when exec and lib files are present
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
