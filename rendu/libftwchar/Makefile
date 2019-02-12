# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:47:48 by abarthel          #+#    #+#              #
#    Updated: 2019/02/07 17:12:29 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To compile with the libftwchar.a, use the command-line: gcc main.c -L. -lftwchar or add it to makefile

NAME = libftwchar.a

CC = gcc

FLAGS = -Werror -Wall -Wextra


############################ OBJECTS #########################################

INCS = -I./utf8/

%.o : %.c
	@$(CC) $(FLAGS) $(INCS) $< -c
	@printf "\e[38;5;127m%-20s \e[38;5;125mobject built\n\e[0m" $(basename $@)

O_FILES	=	ft_fputwc.o ft_fputwcbits.o ft_fputws.o ft_fputwsbits.o ft_fwprintf.o \
			ft_putwchar.o ft_wcscmp.o
#			ft_fwprintf_disp.o

UTF8 = ./utf8/utf8.o

######################### GENERAL RULES ######################################

all: $(NAME)

$(NAME): $(O_FILES)
	@printf "\n"
	@make -C ./utf8/ objects
	@ar rc $(NAME) $(O_FILES) $(UTF8)
	@ranlib $(NAME)
	@printf "\n\e[38;5;198m%4s [\e[1m$(NAME) built]\n\n\e[0m"
	@printf "\e[38;5;90mTo compile with the $(NAME), use the command-line: \e[0m\e[4mgcc main.c -L. -lft\n\e[0m"

clean:
	@make -C ./utf8/ clean
	@rm -f $(O_FILES)
	@printf "\e[0m$(basename $(NAME))%1s\e[0m.o \e[38;5;201mfiles%1sdeleted ♻\n\e[0m"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[0m$(NAME)\e[38;5;201m%8sdeleted ❌\n\e[0m"

re: fclean $(NAME)

# Objects rule to be used when building larger libraries
objects: $(O_FILES)
	@printf "\n"
	@make -C ./utf8/ objects

.PHONY : all clean fclean re objects
