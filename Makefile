NAME				= push_swap
FT_PRINTF			= ./ft_printf/libftprintf.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

FILES 		= commands/push.c \
			commands/reverse_rotate.c \
			commands/rotate.c \
			commands/swap.c \
			push_swap/error.c \
			push_swap/ft_split.c \
			push_swap/init_a_to_b.c \
			push_swap/init_b_to_a.c \
			push_swap/init_stack.c \
			push_swap/libft_new.c \
			push_swap/push_swap.c \
			push_swap/short_stacks.c \
			push_swap/stack_utils.c \
			push_swap/three_sort.c \
			push_swap/utils.c

OBJ					= $(FILES:%.c=$(OBJ_DIR)/%.o)

all: 				$(NAME)

$(NAME): 			$(OBJ) $(FT_PRINTF)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
					@make -C ./ft_printf

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./ft_printf

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(FT_PRINTF)

re: 				fclean all

.PHONY: 			all clean fclean re
