/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                             :+:      :+:    :+:   */
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

typedef	struct			s_pipe
{
	t_cmd_type			type;
	t_cmd				*left;
	t_cmd				*right;
}						t_pipe;
