# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:25:10 by jslusark          #+#    #+#              #
#    Updated: 2024/09/18 17:03:48 by jjs              ###   ########.fr        #
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

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./headers
OFILES = $(CFILES:.c=.o)

CFILES = \
ft_printf.c \
src/ft_printchar.c \
src/ft_printstr.c \
src/ft_printnum.c \
src/ft_printunsigned.c \
src/ft_printhex.c \
src/ft_printpointer.c

all : $(NAME)
	@echo "$(IDLE) $(MAGENTA)$(NAME)$(RESET) is up to date!"

$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)
	ranlib $(NAME)
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) library archived and indexed"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	@echo "$(WARNING) removed $(MAGENTA)ft_printf$(RESET)'s object files"

fclean: clean
	rm -f $(NAME)
	@echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) library"

re: fclean all
	@echo "$(WARNING) recompiled everything from $(MAGENTA)$(NAME)$(RESET)"

.PHONY: all clean fclean re
