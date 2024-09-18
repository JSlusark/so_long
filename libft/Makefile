# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 11:53:09 by jessica           #+#    #+#              #
#    Updated: 2024/09/18 16:46:50 by jjs              ###   ########.fr        #
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

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../headers
OFILES = $(CFILES:.c=.o)

CFILES = \
src/ft_isalpha.c \
src/ft_isdigit.c \
src/ft_isalnum.c \
src/ft_isascii.c \
src/ft_isprint.c \
src/ft_strlen.c \
src/ft_memset.c \
src/ft_bzero.c \
src/ft_memcpy.c \
src/ft_memmove.c \
src/ft_strlcpy.c \
src/ft_strlcat.c \
src/ft_toupper.c \
src/ft_tolower.c \
src/ft_strchr.c \
src/ft_strrchr.c \
src/ft_strncmp.c \
src/ft_memchr.c \
src/ft_memcmp.c \
src/ft_strnstr.c \
src/ft_atoi.c \
src/ft_calloc.c \
src/ft_strdup.c \
src/ft_substr.c \
src/ft_strjoin.c \
src/ft_strtrim.c \
src/ft_putchar_fd.c \
src/ft_putendl_fd.c \
src/ft_putnbr_fd.c \
src/ft_putstr_fd.c \
src/ft_itoa.c \
src/ft_striteri.c \
src/ft_strmapi.c \
src/ft_split.c



all : $(NAME)
	@echo "$(IDLE) $(MAGENTA)$(NAME)$(RESET) is up to date!"

$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)
	@echo "$(SUCCESS) $(MAGENTA)$(NAME)$(RESET) library archived and indexed"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	@echo "$(WARNING) removed $(MAGENTA)libft$(RESET)'s' object files"

fclean: clean
	rm -f $(NAME)
	@echo "$(WARNING) removed $(MAGENTA)$(NAME)$(RESET) library"

re: fclean all
	@echo "$(WARNING) recompiled everything from $(MAGENTA)$(NAME)$(RESET)"

.PHONY: all clean fclean re
