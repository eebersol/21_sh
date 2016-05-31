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

# define WHITESPACES " \t\r\n\v"
# define TOKEN "<|>"
# define MAXARGS 10

enum	e_type
{
	ERRROR,
	EXEC,
	PIPE,
	REDIRECTION,
};

typedef enum e_type		t_type;

typedef	struct			s_cmd
{
	t_type				type;
}						t_cmd;

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

/////////Parser////////////

// ft_build_struct.c
t_cmd	*ft_build_pipe(char *left, char *right);
t_cmd	*ft_build_exec(char *str);

// ft_exec_parser.c
void	ft_exec_pipe(t_cmd *cmd);
int		ft_exec_cmd(t_cmd *cmd);

// ft_parser.c
void	ft_main_parser(void);
t_cmd	*ft_parse_cmd(char *str);

char	*ft_cut_withspace(char *str);
char	*ft_right_body(char *str);

#endif















