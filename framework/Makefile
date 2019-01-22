# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 18:44:30 by pscott            #+#    #+#              #
#    Updated: 2018/12/02 17:56:59 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libunit.a

FLAGS:= -Wall -Werror -Wextra

FRAMEWORK_PATH:= .

LIB_FW:= -L $(FRAMEWORK_PATH)/libfw -lfw
LIB_FW_DIR = $(FRAMEWORK_PATH)/libfw

INCLUDES:= -I $(FRAMEWORK_PATH)/includes

SRC := framework.c format.c processes.c init.c void_function_tests.c
SRCS := $(addprefix $(FRAMEWORK_PATH)/, $(SRC))

OBJS:= $(SRCS:.c=.o)

all: $(NAME)
	@make -C $(LIB_FW_DIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)
	make -C $(LIB_FW_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_FW_DIR) fclean

re: fclean all

.PHONY: clean
