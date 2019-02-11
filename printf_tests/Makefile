# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 18:02:03 by pscott            #+#    #+#              #
#    Updated: 2019/02/11 11:44:46 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit_test
#FLAGS = -Werror -Wall -Wextra

FRAMEWORK_PATH = ../framework


LIB_UNIT_DIR = ../framework
LIB_UNIT = -L $(LIB_UNIT_DIR) -lunit

INCLUDES = -I $(FRAMEWORK_PATH)
SRCS = $(shell find . -type f -name "*.c")

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_UNIT_DIR)
	@gcc $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
#	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
	@printf "\x1b[32;01mcompilation done\x1b[0m"

test: $(NAME)
	@gcc $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
#	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
	@./$(NAME) || true

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<
#	@gcc $(INCLUDES) -o $@ -c $<

clean:
	@make -C $(LIB_UNIT_DIR) clean
	@rm -f $(OBJS)
	@printf "\e[38;5;21mclean done\e[0m\n"

fclean:
	@make -C $(LIB_UNIT_DIR) fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@printf "\e[38;5;31mfclean done\e[0m\n"

re: fclean all

.PHONY: fclean all clean re
