/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

t_cmd	*ft_parse_pipe(char *str)
{
	char	*begin_cmd;
	char	*second_cmd;

	begin_cmd = ft_cut_begin(str, '|');
	second_cmd = ft_cut_second_cmd_pipe(str);
	return (ft_build_pipe(begin_cmd, second_cmd));
}

t_cmd	*ft_parse_redir_right(char *str)
{
	t_list	*list;
	char	*begin_cmd;
	char	*second_cmd;

	begin_cmd = ft_cut_begin(str, '<');
	if (ft_chkrdir(str) == 4)
	{
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '<', 1))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		return (ft_build_redirection(begin_cmd, second_cmd, M_READ, 0));
	}
	else
	{
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '<', 2))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		list = ft_get_opt(second_cmd);
		return (ft_build_heredoc(begin_cmd, list));
	}
}

t_cmd	*ft_parse_redir_left(char *str)
{
	char	*begin_cmd;
	char	*second_cmd;

	begin_cmd = ft_cut_begin(str, '>');
	if (ft_chkrdir(str) == 2)
	{
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '>', 1))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 1));
	}
	else
	{
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '>', 2))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 1));
	}
}

t_cmd	*ft_parse_redir_error(char *str)
{
	char	*begin_cmd;
	char	*second_cmd;

	if (ft_chkrdir_err(str) == 1)
	{
		begin_cmd = ft_cut_begin(str, '2');
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '>', 1))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 2));
	}
	if (ft_chkrdir_err(str) == 2)
	{
		begin_cmd = ft_cut_begin(str, '2');
		if (ft_strlen((second_cmd = ft_cut_secondcmd(str, '>', 2))) == 0)
			return (ft_build_error("21sh : parse error near `\\n'"));
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 2));
	}
	else
		return (ft_parse_redir_error_bis(str));
}

t_cmd	*ft_parse_redir_close(char *str)
{
	char	*begin_cmd;

	if (ft_chkrdir_close(str) == 1)
	{
		begin_cmd = ft_cut_begin(str, '2');
		return (ft_build_redirection(begin_cmd, NULL, 2, 2));
	}
	else
	{
		begin_cmd = ft_cut_begin(str, '1');
		return (ft_build_redirection(begin_cmd, NULL, 1, 1));
	}
}
