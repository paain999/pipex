# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 11:29:44 by dajimene          #+#    #+#              #
#    Updated: 2023/12/23 20:34:10 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f
RF			:= rm -rf

INCLUDE		:= -I ./include/
LIBFT_DIR	:= Libft/
LIBFT		:= Libft/libft.a
OBJ_DIR		:= obj/
SRC_DIR		:= src/

SRC_FILES	:= ${shell find src/ -name "*.c"}

SRC			:= $(SRC_FILES)
OBJ			:= $(subst src/, obj/, $(SRC))
OBJS		:= $(OBJ:.c=.o)

.SILENT:

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c include/pipex.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@echo "\033[33m --Compiling libft--"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\033[0;92m --libft compiled--"
	@echo "\033[33m --Compiling pipex--"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\033[0;92m --pipex compiled--"
	@echo "\033[0;92mUsage: ./pipex infile comando1 comando2 outfile"

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RF) $(OBJ_DIR) 
	$(RM) $(NAME)
	@echo "\033[0;92m--ALL CLEANED!--"
	
re:	fclean all

.PHONY:	all clean fclean re debug