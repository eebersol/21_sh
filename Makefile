# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 19:11:03 by eebersol          #+#    #+#              #
#    Updated: 2016/04/08 19:11:04 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program

NAME			= 21sh

LIB				=	./libft/libft.a

_SRC			= 21sh.c \
					ft_exec.c \
					ft_minishell_exec.c \
					builtin_env/ft_list_to_tab.c \
					builtin_env/ft_env_to_list.c \
					builtin_env/ft_launch_env.c \
					builtin_env/ft_env_set.c  \
					builtin_env/ft_env_get.c \
					builtin_env/ft_env_unset.c \
					editline/ft_is_carac.c \
					editline/ft_is_control.c \
					editline/ft_move_cursor.c \
					editline/ft_add_char.c \
					editline/ft_delete_char.c \
					editline/ft_history.c \
					editline/ft_check_quote.c \
					editline/ft_display_quote.c \
					editline/ft_shift_key.c \
					editline/ft_home_end.c \
					editline/ft_cntrl_d.c \
					utils/ft_lstlen.c \
					utils/ft_get_path.c \
					utils/ft_cut_title.c \
					utils/ft_tputs.c \
					utils/ft_list_show.c \
					utils/ft_free_node.c \
					utils/ft_list_to_string.c \
					utils/ft_string_to_lchar.c \
					init/ft_init_quote.c  \
					init/ft_term_init.c \
					error/ft_error.c \
					prompt/ft_read_prompt.c \
					prompt/ft_clean_prompt.c \
					prompt/ft_reset_prompt.c \
					prompt/ft_init_prompt.c \

INCLUDES		= -I./libft/includes/ -I./includes/

SRC				= $(addprefix srcs/,$(_SRC))

OBJ				= $(SRC:.c=.o)

CFLAGS			= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -ltermcap -o $(NAME)
	@echo $(NAME)" compiled"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Clean all .o files"

fclean:	clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all