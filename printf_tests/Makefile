# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 18:02:03 by pscott            #+#    #+#              #
#    Updated: 2019/01/22 17:55:50 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit_test
FLAGS = -Wall -Werror -Wextra

FRAMEWORK_PATH = ../framework


LIB_UNIT_DIR = ../framework
LIB_UNIT = -L $(LIB_UNIT_DIR) -lunit

INCLUDES = -I $(FRAMEWORK_PATH)
SRCS = $(shell find . -type f -name "*.c")

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_UNIT_DIR)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
	@echo "\x1b[32;01mcompilation done\x1b[0m"

test: $(NAME)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
	@./$(NAME) || true

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_UNIT_DIR) clean
	@echo "\x1b[34;01mclean done\x1b[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_UNIT_DIR) fclean
	@echo "\x1b[31;01mfclean done\x1b[0m"

re: fclean all

.PHONY: fclean all clean re
