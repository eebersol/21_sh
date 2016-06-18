/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define M_WRITE_TRUNC (O_WRONLY | O_NONBLOCK | O_CREAT | O_TRUNC)
# define M_WRITE_APPEND (O_WRONLY | O_NONBLOCK | O_CREAT | O_APPEND)
# define M_READ_TRUNC (O_RDONLY | O_NONBLOCK | O_CREAT | O_TRUNC)
# define M_READ_APPEND (O_RDONLY | O_NONBLOCK | O_CREAT | O_APPEND)
# define M_READ (O_RDONLY | O_NONBLOCK | O_CREAT)

enum					e_type
{
	ERROR,
	EXEC,
	PIPE,
	REDIRECTION,
	HEREDOC,
};

typedef enum e_type		t_type;

typedef	struct			s_cmd
{
	t_type				type;
}						t_cmd;

typedef struct			s_error
{
	t_type				type;
	char				*msg_err;
}						t_error;

typedef struct			s_exec
{
	t_type				type;
	char				*cmd;
	char				**opt;
}						t_exec;

typedef	struct			s_redirection
{
	t_type				type;
	t_cmd				*cmd;
	char				*file;
	int					mode;
	int					fd;
}						t_redirection;

typedef	struct			s_pipe
{
	t_type				type;
	t_cmd				*left;
	t_cmd				*right;
}						t_pipe;

typedef	struct			s_heredoc
{
	t_type				type;
	t_cmd				*left;
	t_list				*right;
}						t_heredoc;
/*
**	ft_build_struct.c
*/
t_cmd					*ft_build_pipe(char *left, char *right);
t_cmd					*ft_build_exec(char *str);
t_cmd					*ft_build_redirection(char *cmd,
										char *file, int mode, int fd);
t_cmd					*ft_build_heredoc(char *left, t_list *list);
t_cmd					*ft_build_error(char *msg_error);
/*
** ft_exec_parser.c
*/
void					ft_exec_pipe(t_cmd *cmd);
void					ft_exec_cmd(t_cmd *cmd);
void					ft_exec_redirectiont(t_cmd *cmd);
void					ft_exec_heredoc(t_cmd *cmd);
void					ft_exec_redirection_bis(t_cmd *cmd);
/*
** ft_parser.c
*/
void					ft_main_parser(void);
t_cmd					*ft_parse_cmd(char *str);
t_list					*ft_get_opt(char *str);
char					*ft_cut_withspace(char *str);
char					*ft_rbody(char *s1);
char					*ft_cut_second_cmd_pipe(char *str);
/*
** ft_fn_exec.c
*/
void					ft_exec_simple_cmd(t_cmd *cmd);
/*
** ft_parse_redir
*/
t_cmd					*ft_parse_redir_right(char *str);
t_cmd					*ft_parse_redir_left(char *str);
t_cmd					*ft_parse_redir_error(char *str);
t_cmd					*ft_parse_pipe(char *str);
/*
** ft_check
*/
int						ft_chkrdir(char *s1);
int						ft_chkrdir_err(char *s1);
int						ft_chkrdir_close(char *s1);
t_cmd					*ft_parse_redir_close(char *str);
#endif
