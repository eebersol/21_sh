/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[37m"
# define HOME ((b[0] == 27 && b[1] == 91 && b[2] == 72))
# define END ((b[0] == 27 && b[1] == 91 && b[2] == 70))
# define TOP ((b[0] == 27 && b[1] == 91 && b[2] == 65))
# define BOT ((b[0] == 27 && b[1] == 91 && b[2] == 66))
# define RIGHT ((b[0] == 27 && b[1] == 91 && b[2] == 67))
# define LEFT ((b[0] == 27 && b[1] == 91 && b[2] == 68))
# define SPACE ((b[0] == 32))
# define ESC ((b[0] == 27 && b[1] == 0) && b[3] == 0)
# define ENTER ((b[0] == 10))
# define IS_ARROW (b[0] == 27)
# define CNTRL (b[0] == 4 || b[0] == 3)
# define BACK_SPACE (b[0] == 127)
# define DELETE ((b[0] == 127 && b[1] == 0 && b[2] == 0))
# define SHIFT_R (b[0] == 27 && b[1] == 91 && b[2] == 49 && b[5] == 67)
# define SHIFT_L (b[0] == 27 && b[1] == 91 && b[2] == 49 && b[5] == 68)
# define CNTRL_D (b[0] == 4 && b[1] == 0 && b[2] == 0 && b[3] == 0)

typedef struct termios	t_termios;

typedef struct  	s_quote
{
	int 			parenth_1;
	int 			parenth_2;
	int 			double_quote;
	int 			simple_quote;
	int 			black_quote;
	int 			hook_1;
	int 			hook_2;
	int 			accolade_1;
	int 			accolade_2;
} 					t_quote;

typedef	struct 		s_prompt
{
	int 			x;
	int 			y;
	t_list			*l_char;
	t_list 			*history;
	int				lenght;
	int 			history_len;
	int				index;
	int 			index_history;
	int 			first_top;
	int 			first_process;
	int 			quote_value;
	int 			quote_value_parenth;
	int 			quote;
	int 			first_move_word;
	int 			index_word;
	char 			*complet_prompt;
	int 			index_d;
}					t_prompt;

typedef struct		s_env
{
	char			*var;
	char 			*value;
}					t_env;

typedef struct		s_sh
{
	t_list			*env;
	t_termios		term;
	t_prompt 		*prompt;
	char			*term_name;
}					t_sh;

// BUILTIN_ENV //
void	ft_env_to_list(t_list **list, char **environ);
char	**ft_list_to_tab(t_list **list);
void	ft_launch_env(t_sh *sh, char **environ);
void	ft_env_set(t_list **list, char *var, char *value);
char	*ft_env_get(t_list *list, char *var);
t_list	*ft_env_unset(t_list **list, char **cmd);



// ERROR //
void	ft_error_ac(void);
void	ft_error_not_found(char *varname);


// PROMPT //
char	*ft_read_prompt(void);

// EDITLINE //
void	ft_term_init(t_sh *sh);
void	ft_is_carac(char *b);
void	ft_is_control(char *b);
void	ft_move_cursor(char *b);
void	ft_arrow_right(void);
void	ft_arrow_left(void);
void	ft_delete_char(void);
void	ft_add_to_history(char *str);
void	ft_history(void);
void	ft_move_top(void);
void	ft_move_bot(void);
int		ft_reset_prompt(void);
void	ft_add_char(char *b);
			// quote //
int 	ft_check_quote(void);
int 	ft_check_number_quote(t_quote quote, t_prompt *prompt);
int	 	ft_check_double_quote(t_quote quote, t_prompt *prompt);
int 	ft_check_simple_quote(t_quote quote, t_prompt *promt);
int 	ft_check_black_quote(t_quote quote, t_prompt *promt);
int		ft_check_parenth_quote(t_quote quote, t_prompt *prompt);
void	ft_cntrl_d(void);

void 	ft_move_word_left(t_prompt *prompt);
void	ft_move_word_right(t_prompt *prompt);
void	ft_move_word(char *b);

void 	ft_go_home(void);
void 	ft_go_end(void);

// UTILS //
int		ft_lstlen(t_list *list);
int		ft_cut_title(char *str);
int		tputs_putchar(int c);
void	ft_list_show(t_list *list);
void	ft_list_shower(t_list *list, t_prompt *prompt);
void	ft_free_node(void *content, size_t size);
char	*ft_list_to_string(void);
void	ft_clean_prompt(void);
void 	ft_clean_history(char *str);
char	*ft_get_path(t_list *list, char *b);
void 	ft_history_to_lchar(char *str);

// MAIN //
t_sh	*ft_sh(void);

// INIT //
void	ft_init_prompt(void);
void	ft_init_sh(void);
t_quote	ft_init_quote(void);






int		ft_exec(char **cmd, char **env);
void	minishell_exec(t_list *env, char **cmd);
void	ft_(void);
#endif






























