# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:29:39 by gule-bat          #+#    #+#              #
#    Updated: 2024/12/20 16:44:25 by gule-bat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
.SILENT:
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
#end

NAME = libftprintf.a

SRCS =	ft_printf.c		printfplus.c	testing.c	libftelse.c

OBJS = $(SRCS:.c=.o) 

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(MAGENTA) Archive en fabrication ... $(RESET)"
	@$(MAKE) tab
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)ARCHIVE $(NAME) CRÉE$(RESET)"


tab: 
	@sleep 0.1
	@echo "[$(YELLOW)....$(RESET)]"
	@sleep 0.3
	@echo "[$(BLUE)/...$(RESET)]"
	@sleep 0.3
	@echo "[$(MAGENTA)//..$(RESET)]"
	@sleep 0.3
	@echo "[$(CYAN)///.$(RESET)]"
	@sleep 0.3	
	@echo "[$(RED)////$(RESET)]"
	@sleep 0.3

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA) Archive en supression. $(GREEN)$(RESET)"
	@sleep 0.3
	@echo "$(MAGENTA) . $(GREEN)$(RESET)"
	@sleep 0.3
	@echo "$(MAGENTA) .. $(GREEN)$(RESET)"
	@sleep 0.3
	@echo "$(MAGENTA) ...\n $(GREEN)$(RESET)"
	@sleep 0.3
	@sleep 0.3	
	@echo "$(GREEN)ft_printf.o, printfplus.o et testing.o correctement effacés.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) effacé, ALL CLEARED\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
