# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:49:39 by jjs               #+#    #+#              #
#    Updated: 2024/09/17 16:37:32 by jjs              ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror #-g
REMOVE = rm -rf

# Directories
MLX_DIR = minilibx-linux
LIBFT_DIR = Libft
PRINTF_DIR = ft_printf

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBS = -L/usr/X11/lib -lXext -lX11 -lm -lbsd #for linux
# LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKi #for mac

# Source files
SRC = main.c
OBJ = $(SRC:.c=.o)

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

#Executable name
NAME = so_long

# Default target, includes a conditional that decides wheter to compile the project or not if it's there/not-there
all: check_already_compiled

# Check if the executable already exists
check_already_compiled:
	@if [ -f $(NAME) ]; then \
		echo "$(IDLE) No changes detected, nothing to compile."; \
	else \
		$(MAKE) $(NAME); \
	fi

$(MLX_LIB):
	@make -C $(MLX_DIR) --silent

# later add also compilation for libft, printf and getnextline
$(NAME): $(OBJ) $(MLX_LIB)
	@$(CC) $(CFLAGS) -I. $(OBJ) $(MLX_LIB) $(LIBS) -o $(NAME)
	@echo "$(SUCCESS) So_long program was compiled successfully!"

# Clean up object files - ADD IF AND ELSE STATEMENTS TO AVOID CLEANING WHEN NOT NEEDED
clean:
	@$(REMOVE) $(OBJ)
	@make -C $(MLX_DIR) clean --silent
	@echo "$(WARNING) Cleaned up all object files."

# Full clean up including libraries and executables
fclean: clean
	@$(REMOVE) $(NAME)
	@make -C $(MLX_DIR) clean --silent
	@echo "$(WARNING) Full clean including executables and libraries."

# Recompile everything
re: fclean all
	@echo "$(SUCCESS) Re-comipilation executables and libraries"

%:
	@echo "$(FAILURE) target '$@' is not a valid target.$(RESET)"
	@echo "Please use one of the following valid targets:"
	@echo "- $(GREEN)make$(RESET): compiles the project"
	@echo "- $(GREEN)make re$(RESET): recompiles the project"
	@echo "- $(GREEN)make clean$(RESET): removes object files"
	@echo "- $(GREEN)make fclean$(RESET): removes object files and the final library"

.PHONY: all clean fclean re %
