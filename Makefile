# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 15:02:03 by gule-bat          #+#    #+#              #
#    Updated: 2025/04/17 22:12:52 by gule-bat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
#\033[u 
VOID =  \033[2J
#\033[2J 
#end

NAME = clv


SRCS =  imageloaderxpm.c

INCLUDES = -I ./includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3 -o $(NAME) $(INCLUDES)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(MAGENTA) Compilation de Fractol en cours ... $(RESET)"
	@cd mlx_linux || make clean || make || ..
	@$(MAKE) tabfast
	@cc -Wall -Wextra -Werror $(SRCS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -Lftprintf -lftprintf -Ilibftprintf -lXext -lX11 -lm -lz -g3 -O2 -o $(NAME)
#\	-L./includes/  -lftprintf
	@echo "$(GREEN)Fractol $(NAME) CRÉÉ$(RESET)"
	@sleep 0.1

tab:
	@sleep 0.1
	@echo "[$(YELLOW)....$(RESET)]"
	@sleep 0.2
	@echo "$(VOID)"
	@echo "[$(YELLOW)/...$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(MAGENTA)//..$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(MAGENTA)///.$(RESET)]"
	@sleep 0.2
	@echo "$(VOID)"
	@echo "[$(RED)////$(RESET)]"
	@sleep 0.2
	@echo "$(VOID)"
	@sleep 0.4
	@echo "[$(GREEN)✓✓✓✓$(RESET)]"
	@sleep 0.1
	@echo "\t$(GREEN)COMPILED$(RESET)\t"
	@sleep 0.2

tabfast:
	@sleep 0.1
	@echo "[$(YELLOW)....$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(YELLOW)/...$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(MAGENTA)//..$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(MAGENTA)///.$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@echo "[$(RED)////$(RESET)]"
	@sleep 0.1
	@echo "$(VOID)"
	@sleep 0.1
	@echo "[$(GREEN)✓✓✓✓$(RESET)]"
	@sleep 0.1
	@echo "\t$(GREEN)COMPILED$(RESET)\t"
	@sleep 0.2

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA) Archive en supression ... \n $(GREEN)$(RESET)"
	@echo "$(GREEN)Fractol correctement effacé.$(RESET)"


fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Fractol, $(NAME) et son stuff,\n correctement effacés.$(RESET)"

re: fclean all

r: all clean tabfast

.PHONY: all clean fclean re%   
