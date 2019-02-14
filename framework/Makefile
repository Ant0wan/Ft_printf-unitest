# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 16:55:38 by abarthel          #+#    #+#              #
#    Updated: 2019/02/14 13:04:12 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libunit.a

#FLAGS			= 	-Wall -Werror -Wextra

FRAMEWORK_PATH	=	.

INCLUDES		=	-I $(FRAMEWORK_PATH)

SRC				=	framework.c format.c processes.c init.c libtools.c

SRCS			=	$(addprefix $(FRAMEWORK_PATH)/, $(SRC))

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\e[38;5;231mLi\e[38;5;230mbu\e[38;5;223mnit frammewo\e[38;5;230mrk\e[38;5;231m built\n\e[0m"

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@printf "\e[38;5;231mFra\e[38;5;230mmew\e[38;5;223mork \e[0m.o\e[38;5;223m fi\e[38;5;230mles del\e[38;5;231meted\e[0m\n"

fclean:	clean
	@rm -f $(NAME)
	@printf "\e[38;5;231mFra\e[38;5;230mmew\e[38;5;223mork \e[0m.a\e[38;5;230m del\e[38;5;231meted\e[0m\n"

re:	fclean all

.PHONY:	all clean fclean re
