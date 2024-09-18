# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:25:10 by jslusark          #+#    #+#              #
#    Updated: 2024/09/18 15:19:38 by jjs              ###   ########.fr        #
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
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) ready for use!"

$(NAME) : $(OFILES)
	$(MAKE) -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OFILES)
	ranlib $(NAME)
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) library archived and indexed"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ../libft
	rm -f $(OFILES)
	@echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) object files"

fclean: clean
	$(MAKE) fclean -C ../libft
	rm -f $(NAME)
	@echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) library"

re: fclean all
	@echo "$(WARNING) recompiled everything from $(MAGENTA)$(NAME)$(RESET)"

.PHONY: all clean fclean re
