# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marobert <marobert@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 16:06:19 by marobert          #+#    #+#              #
#    Updated: 2023/04/19 10:56:42 by marobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Colors from https://misc.flogisoft.com/bash/tip_colors_and_formatting#colors1
RED			=	\033[31m
GREEN		=	\033[32m
CYAN		=	\033[34m
IGREY		=	\033[0;48m
END			=	\033[0m
ERASE		=	\033[2K\r


SRCS		=	srcs/main.c \
				srcs/utils/ft_intlen.c\
				srcs/utils/envp_utils.c\
				srcs/utils/t_str.c\
				srcs/utils/tab_utils.c\
				srcs/utils/utils.c\
				srcs/utils/utils_hd.c\
				srcs/sigs/handle.c\
				srcs/sigs/init.c\
				srcs/parsing/sort_args.c\
				srcs/exec/multi_pipes.c\
				srcs/exec/dup.c\
				srcs/exec/pipes.c\
				srcs/exec/utils_exec.c\
				srcs/exec/free_exec.c\
				srcs/exec/cmds.c\
				srcs/exec/exec_cmd.c\
				srcs/exec/files.c\
				srcs/exec/check_err.c\
				srcs/exec/here_doc.c\
				srcs/exec/builtin/bt_cd.c\
				srcs/exec/builtin/bt_exit.c\
				srcs/exec/builtin/bt_echo.c\
				srcs/exec/builtin/bt_pwd.c\
				srcs/exec/builtin/bt_env.c\
				srcs/exec/builtin/bt_unset.c\
				srcs/exec/builtin/bt_export.c\
				srcs/utils/lst_utils.c\
				srcs/utils/parse_utils.c\
				srcs/utils/heredoc_utils.c\
				srcs/parsing/get_args.c\
				srcs/parsing/expand_args.c\
				srcs/parsing/split_args.c \
				srcs/utils/exec_utils.c

DIR_SRCS	=	srcs
DIR_INCS	=	libft includes
DIR_BUILD	=	.build/
OBJS		=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS		=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
LIBFT		=	libft/libft.a
LIBFT_DIR	=	./libft
DEPS_FLAGS	=	-MMD -MP
CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g3 #-fsanitize=address
CFLAGS		+=	#-I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib -g3
NAME_FLAGS	=	-lreadline
NAME		=	minishell

all:		lib $(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@printf "[$(CYAN)Compiling$(END)] % 25s" $(NAME)
			@$(CC) $(CFLAGS) $(DIR_INCS:%=-I %) -o $(NAME) $(OBJS) $(LIBFT) $(NAME_FLAGS)
			@printf "$(ERASE)[$(GREEN)Done$(END)] % 30s\n" $(NAME)

.PHONY:		lib
lib:
			@make -C $(LIBFT_DIR)

-include $(DEPS)

$(DIR_BUILD)%.o : %.c
			@printf "[$(CYAN)Compiling$(END)] % 25s" $(patsubst $(shell dirname $<)/%, %, $<)
			@mkdir -p $(shell dirname $@)
			@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(DIR_INCS:%=-I %) -c $< -o $@
			@printf "$(ERASE)[$(GREEN)Done$(END)] % 30s\n" $(patsubst $(shell dirname $<)/%, %, $<)

clean:
			@$(RM) $(DIR_BUILD)
			@printf "[$(RED)Deleted$(END)] % 27s\n" "$(NAME) objects"

fclean:		clean
			@$(RM) $(NAME)
			@printf "[$(RED)Deleted$(END)] % 27s\n" $(NAME)

re:			fclean
			@make all

.PHONY: norme
norme:
			norminette $(SRCS) $(DIR_INCS) | grep -v 'OK!' | cat

.PHONY: shrek
shrek:
		@echo "$(GREEN)⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ "
		@echo "⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿ "
		@echo "⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀ "
		@echo "⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉$(END)"

.PHONY: 42
42:
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡴⠶⠶⠶⠖⠲⠤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠈⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠄⣴⡚⢀⣼⠏⠀⠀⠀⠀⣀⣀⠀⢀⣀⣀⠀⣴⡿⢶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠈⢀⢎⢞⣁⣿⡇⠀⠀⠀⠀⠀⣇⠈⠉⠉⠀⠉⠉⣿⡂⡄⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢄⡀⠀⠁⣄⣢⣾⣿⣾⣿⣿⡇⠀⠀⠀⠀⢀⣼⠀⠀⢀⣀⣀⣀⣹⣷⣅⣜⣮⣳⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣼⣾⣿⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⡅⣰⣞⡉⢳⣤⡷⠀⠊⢭⠶⠶⠸⣿⣿⣿⣿⣿⣿⣾⣿⣟⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⣹⣦⠁⠀⠀⠀⠀⠀⣤⣠⣙⣿⣿⣿⣿⣿⣿⣿⣿⣿⠤⠀⠀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⢠⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⣭⣤⠀⠀⠀⠀⠀⠀⢤⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣝⣦⡀⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⠀⣾⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡇⠀⠀⠀⠀⣀⣀⣀⣀⡀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠀⣾⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⢯⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⠄⣲⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠋⠁⠀⠈⣧⠳⡄⠀⠀⠀⠀⠀⡾⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠉⠁⠀⢸⡀⠀⠀⠀⢻⠀⠙⢦⡀⠀⠀⡼⠀⢸⣿⣓⣚⡺⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠈⣧⠀⠀⠀⠘⣇⣀⣤⣿⠶⣾⡁⠀⣸⣿⣿⣿⡇⡇⢸⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣽⣿⡆⠀⠀ $(END)"
		@echo "$(IGREY)   ⢀⣴⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠠⡖⠋⠉⠀⠀⠀⠀⠘⣟⠳⠿⣝⣶⣿⢿⠃⢿⣒⣒⣰⠃⠈⡆⠀⢸⣿⣿⣿⣿⣿⣿⣿⡿⣿⠇⠀⠀ $(END)"
		@echo "$(IGREY)   ⢠⣼⣿⣿⣿⣿⣿⣿⣿⠿⠀⠀⠀⠀⢰⡀⠀⠹⡄⠀⠀⠀⠀⠀⠀⠘⣗⠒⠶⠶⠾⠽⡇⢠⡏⠈⡇⠀⠀⡇⠀⣀⣿⣿⣿⣿⣿⣿⣯⠾⣿⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⢻⣿⣿⣿⣿⣿⣿⠇⢸⠀⠀⠀⠀⠀⣧⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⢸⣉⡉⠒⠲⠶⡇⢸⡇⠀⡇⠀⠸⡃⢠⠏⣻⣿⣿⣿⣿⣿⣿⣮⠁⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⢿⣿⣿⣿⣿⣿⣿⠀⠈⣇⠀⠀⠀⠀⠈⡇⠀⠀⠳⡀⠀⠀⠀⠀⠀⠈⣧⠉⠽⠿⣺⡇⠈⢷⡤⠇⠀⢀⡿⠈⡇⠸⣿⣿⣿⣿⣿⣿⠙⠀⠀⠀⠀ $(END)"
		@echo "$(IGREY)   ⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠘⣆⠀⠀⠀⠀⡟⠀⠀⠀⠙⠢⣄⠀⠀⠀⠀⠹⣟⣛⣓⣒⡇⠀⢸⡇⠀⣠⠟⠀⢸⠀⠀⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀ $(END)"

.PHONY:		all clean fclean re
