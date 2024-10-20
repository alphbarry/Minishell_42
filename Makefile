# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 20:20:40 by cgomez-z          #+#    #+#              #
#    Updated: 2024/10/20 19:57:23 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<--------------------------------->COLORS<----------------------------------->#
DEF_COLOR	=	\033[1;99m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
PINK		=	\033[1;95m
CIAN		=	\033[1;96m

#<--------------------------------->NAME<------------------------------------>#
NAME		=	minishell

#<-------------------------------->HEADERS<---------------------------------->#
HEADER		=	./inc/

#<--------------------------------->DIRS<------------------------------------>#
SRC_DIR		=	src/
OBJ_DIR		=	objects/

#<--------------------------------->FILES<---------------------------------->#
FILES		=	main.c \
				tokens.c

#<--------------------------------->SRCS<----------------------------------->#
SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

#<----------------------------->OBJS && DEPS<------------------------------->#
OBJS		=	$(addprefix $(OBJ_DIR), $(subst .c,.o,$(FILES)))
DEPS		=	$(subst .o,.d,$(OBJS))

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		=	-I$(HEADER)
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -lreadline #-fsanitize=address
MKFLAGS		=	--no-print-directory

#<--------------------------------->RULES<----------------------------------->#
$(OBJ_DIR)%.o	:$(SRC_DIR)%.c $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)    \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)       \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

all				:
	@$(MAKE) $(MKFLAGS) $(NAME)


$(NAME)			:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\n$(GREEN)Minishell has been compiled$(DEF_COLOR)"

clean			:
	@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
	@echo ""
	@echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	@echo ""

fclean			:
	@$(MAKE) $(MKFLAGS) clean
	@$(RM) $(NAME) $(B_NAME)
	@echo ""
	@echo "$(RED)Program has been removed$(DEF_COLOR)"

re				:
	@$(MAKE) $(MKFLAGS) fclean
	@$(MAKE) $(MKFLAGS) all
	@echo ""
	@echo "$(CIAN)Minishell has been recompiled$(DEF_COLOR)"

.PHONY			: all clean fclean re

-include		$(DEPS)
