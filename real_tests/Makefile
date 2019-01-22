# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 18:01:47 by pscott            #+#    #+#              #
#    Updated: 2018/12/02 22:32:47 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit_test
FLAGS = -Wall -Werror -Wextra

FRAMEWORK_PATH = ../framework


LIB_UNIT_DIR = ../framework
LIB_UNIT = -L $(LIB_UNIT_DIR) -lunit

LIB_FW_DIR = $(FRAMEWORK_PATH)/libfw
LIB_FW = -L $(LIB_FW_DIR) -lfw

PROJECT_NAME = libft
LIB_TEST_NAME = ft
RENDU = ../rendu
LIB_TEST_DIR = $(RENDU)/$(PROJECT_NAME)
LIB_TEST = -L $(LIB_TEST_DIR) -l$(LIB_TEST_NAME)

INCLUDES = -I $(FRAMEWORK_PATH)/includes -I $(LIB_TEST_DIR)
SRCS = $(shell find . -type f -name "*.c")

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_UNIT_DIR)
	@make -C $(LIB_TEST_DIR)
	gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_FW) $(LIB_TEST) -o $(NAME) $(OBJS)

test: $(NAME)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_FW) $(LIB_TEST) -o $(NAME) $(OBJS)
	@./$(NAME)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)
	@make -C $(LIB_UNIT_DIR) clean
	@make -C $(LIB_TEST_DIR) clean


fclean: clean
	rm -f $(NAME)
	@make -C $(LIB_UNIT_DIR) fclean
	@make -C $(LIB_TEST_DIR) fclean


re: fclean all

.PHONY: fclean all clean
