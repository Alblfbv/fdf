# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 12:50:11 by rkirszba          #+#    #+#              #
#    Updated: 2019/09/24 14:36:57 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_PATH = ./libft

SRC_PATH = src
SRC_NAME = fdf.c\
		   parsing.c\
		   init_fdf.c\
		   reinit_matrices.c\
		   reinit_matrices_proj.c\
		   projection_process.c\
		   draw_object.c\
		   draw_object_utils.c\
		   events_handlers.c\
		   key_events_handlers.c\
		   key_events_handlers2.c\
		   free_functions.c\
		   errors.c

HEADER_PATH = ./includes/
HEADEAR_NAME = fdf.h
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

LIB_PATH = ./libft
LIB_HEADER_NAME = libft.h
LIB_HEADER_PATH = $(addprefix $(LIB_PATH)/, includes)
LIB_NAME = libft.a
LIB_HEADER = $(addprefix $(LIB_HEADER_PATH)/, $(LIB_HEADER_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

LIB_MLX_PATH = ./libmlx
LIB_MLX_HEADER_NAME = libmlx.h
LIB_MLX_HEADER_PATH = $(addprefix $(LIB_MLX_PATH)/, includes)
LIB_MLX_NAME = libmlx.a
LIB_MLX_HEADER = $(addprefix $(LIB_MLX_HEADER_PATH)/, $(LIB_MLX_HEADER_NAME))
LIB_MLX = $(addprefix $(LIB_MLX_PATH)/, $(LIB_MLX_NAME))


OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CCFLAGS = -g\
		  -Wall\
		  -Wextra\
		  -Werror\
#		  -fsanitize=address

CPPFLAGS = -I $(HEADER_PATH) -MMD

MLX_FLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libs $(NAME)

libs:
	@make -C libft/
	@make -C libmlx/

$(NAME): $(OBJ)
	@make -C libft/
	@make -C libmlx/
	$(CC) $(CCFLAGS) $^ -o $@ $(LIB) $(LIB_MLX) $(MLX_FLAGS)
	@echo "made fdf"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -I$(LIB_HEADER_PATH) -I$(LIB_MLX_HEADER_PATH) -o $@ -c $<

#-I$(LIB_HEADER_PATH) $(LIB) -I$(LIB_MLX_HEADER_PATH) $(LIB_MLX)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	@echo "cleaned fdf"
	@make clean -C libft/
	@make clean -C libmlx/
	@rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@echo "fcleaned fdf"
	@make fclean -C libft/
	@make fclean -C libmlx/
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

norme:
	norminette $(SRC)
	norminette $(HEADER_PATH)

.PHONY:		lib make clean fclean re san
.SILENT:	$(OBJ) $(NAME) all clean fclean re

-include $(OBJ:.o=.d)
