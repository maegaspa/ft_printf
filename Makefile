# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/06 16:29:54 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/06/14 20:42:47 by maegaspa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = /includes/printf.h

FILES = src/nsm\
		src/util\
		src/util2\
		src/util3\
		src/wp_streat\
		src/wp_dtreat\
		src/wp_dtreat2\
		src/wp_otreat\
		src/wp_otreat2\
		src/wp_otreat3\
		src/wp_oxtreat\
		src/wp_oxtreat2\
		src/wp_utreat\
		src/wp_utreat2\
		src/wp_ctreat\
		src/ft_atoi_2\
		src/wp_ptreat\
		src/ft_strcaps\
		

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation"
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rcs  $(NAME) $(OBJ)
	@ranlib $(NAME)
	
object/%.o	:	%.c $(INC)
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@echo "	 ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "	██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "	██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗    ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "	██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║    ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "
	@echo "	╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝    ██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "
	@echo "	 ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "
	@rm -f $(OBJ)
	@make clean -C libft/

onlylibft:
	@make -C libft/

fclean: clean
	@echo "--------------------------------------------"
	@echo "\n- Cleaning 'libft.a' and libftprintf.a -"
	@echo "\n--------------------------------------------"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
