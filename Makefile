# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 18:04:39 by qurobert          #+#    #+#              #
#    Updated: 2021/05/17 09:59:27 by qurobert         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME_P = 	push_swap
NAME_C =	checker
FILES_P = 	error.c check.c print.c main_p.c op.c r_op.c algo.c tab.c \
			check_op.c push.c tool.c tools.c
FILES_C =	checker.c op.c r_op.c main_c.c check.c error.c print.c algo.c tab.c\
			check_op.c push.c tool.c tools.c
INC_FILES = push_swap.h color.h
INC_PATH = 	./includes/
SRC_PATH = 	./srcs/
INC 	= 	$(addprefix ${INC_PATH},${INC_FILES})
SRC_P = 	$(addprefix ${SRC_PATH},${FILES_P})
SRC_C =		$(addprefix ${SRC_PATH},${FILES_C})
CC = 		clang
OBJ_P = 	${SRC_P:.c=.o}
OBJ_C = 	${SRC_C:.c=.o}
FLAGS = 	-Wall -Wextra -Werror

all: 		$(NAME_P) $(NAME_C)

lib:
		@make -C ./libft
		@cp ./libft/libft.a .

$(NAME_P): 	lib $(OBJ_P)
			@${CC} $(FLAGS) $(OBJ_P) libft.a -L. -o $(NAME_P)

$(NAME_C): 	lib $(OBJ_C)
			@${CC}  $(FLAGS) $(OBJ_C) libft.a -L. -o $(NAME_C)
			
%.o : %.c	$(INC)
			@$(CC) $(FLAGS) -I$(INC_PATH) -c $< -o $@
			@printf '\033[2J'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿            ____________________________       \n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⠛⢩⣴⣶⣶⣶⣌⠙⠫⠛⢋⣭⣤⣤⣤⣤⡙⣿⣿⣿⣿⣿⣿            !\_________________________/! \\   \n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⡟⢡⣾⣿⠿⣛⣛⣛⣛⣛⡳⠆⢻⣿⣿⣿⠿⠿⠷⡌⠻⣿⣿⣿⣿            !!                         !! \\   \n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⠏⣰⣿⣿⣴⣿⣿⣿⡿⠟⠛⠛⠒⠄⢶⣶⣶⣾⡿⠶⠒⠲⠌⢻⣿⣿            !!                         !!  \\  \n\033[0m'
			@printf '\033[32m⣿⣿⠏⣡⢨⣝⡻⠿⣿⢛⣩⡵⠞⡫⠭⠭⣭⠭⠤⠈⠭⠒⣒⠩⠭⠭⣍⠒⠈⠛            !!                         !!  !   \n\033[0m'
			@printf '\033[32m⡿⢁⣾⣿⣸⣿⣿⣷⣬⡉⠁⠄⠁⠄⠄⠄⠄⠄⠄⠄⣶⠄⠄⠄⠄⠄⠄⠄⠄⢀            !!                         !!  !   \n\033[0m'
			@printf '\033[32m⢡⣾⣿⣿⣿⣿⣿⣿⣿⣧⡀⠄⠄⠄⠄⠄⠄⠄⢀⣠⣿⣦⣤⣀⣀⣀⣀⠄⣤⣾            !!     \033[31m ➜ $(notdir $<)     \n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⡶⢇⣰⣿⣿⣟⠿⠿⠿⠿⠟⠁⣾⣿⣿            !!                         !!  !   \n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⡟⢛⡛⠿⠿⣿⣧⣶⣶⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣧⠸⣿⣿            !!                         !!  !   \n\033[0m'
			@printf '\033[32m⠘⢿⣿⣿⣿⣿⣿⡇⢿⡿⠿⠦⣤⣈⣙⡛⠿⠿⠿⣿⣿⣿⣿⠿⠿⠟⠛⡀⢻⣿            !!                         !!  /   \n\033[0m'
			@printf '\033[32m⠄⠄⠉⠻⢿⣿⣿⣷⣬⣙⠳⠶⢶⣤⣍⣙⡛⠓⠒⠶⠶⠶⠶⠖⢒⣛⣛⠁⣾⣿            !!_________________________!! /    \n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠈⠛⠛⠿⠿⣿⣷⣤⣤⣈⣉⣛⣛⣛⡛⠛⠛⠿⠿⠿⠟⢋⣼⣿⣿            !/_________________________\!/     \n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠉⣻⣿⣿⣿⣿⡿⠿⠛⠃⠄⠙⠛⠿⢿⣿               __\_________________/__/!_  	  \n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢬⣭⣭⡶⠖⣢⣦⣀⠄⠄⠄⠄⢀⣤⣾⣿             /oooo  oooo  oooo  oooo /!    	  \n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⣶⣶⣶⣾⣿⣿⣿⣿⣷⡄⠄⢠⣾⣿⣿⣿            /ooooooooooooooooooooooo/ /   	  \n\033[0m'
			@printf '\033[32m	                                 /ooooooooooooooooooooooo/ /		  \n\033[0m'
			@printf '\033[32m	                                /_______________________/_/		  \n\033[0m'
			@printf '\033[32m \n\033[0m'
			@sleep 0.25
			
clean:		
			@rm -f ${OBJ_P} $(OBJ_C)
			@make clean -C ./libft
			@printf '\033[32m %s\n\033[0m'
			@printf '\033[33m⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀ ⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀             ⠀⢸⣿⣿ %s\n\033[0m'
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ FILES DELETED   ⢸⣿⣿ %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'

fclean:		clean
			@rm -f ${NAME_P} $(NAME_C)
			@cd ./libft && rm -f libft.a
			@rm libft.a
			@printf '\033[31m⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀ ⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀             ⠀⢸⣿⣿ %s\n\033[0m'
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ LIBFT.A DELETED ⢸⣿⣿ %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'
			
re:			fclean all

.PHONY: all clean fclean re lib
