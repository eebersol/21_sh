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

#include <21sh.h>

t_cmd	*ft_parse_redir_right(char *str, char *begin_cmd, char *second_cmd)
{
	t_list	*list;
	char	*p_str;

	p_str = ft_strnew(1);
	if ((*p_str = ft_strchr(str, '<') != NULL) && ft_chkrdir(str) == 0)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		return (ft_build_redirection(begin_cmd, second_cmd, M_READ_APPEND, 0));
	}
	else
	{
		begin_cmd = ft_cut_begin_doubleredir(str, '<');
		second_cmd = ft_cut_second_doubleredir(str, '<', 2);
		list = ft_get_opt(second_cmd);
		return (ft_build_heredoc(begin_cmd, list));
	}
}

t_cmd	*ft_parse_redir_left(char *str, char *begin_cmd, char *second_cmd)
{
	char	*p_str;

	p_str = ft_strnew(1);
	if ((*p_str = ft_strchr(str, '>') != NULL) && ft_chkrdir(str) == 0)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 1));
	}
	else
	{
		begin_cmd = ft_cut_begin_doubleredir(str, '>');
		second_cmd = ft_cut_second_doubleredir(str, '>', 2);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 1));
	}
}

t_cmd	*ft_parse_redir_error(char *str, char *begin_cmd, char *second_cmd)
{
	if (ft_chkrdir(str) == 3)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 2));
	}
	if (ft_chkrdir(str) == 4)
	{
		second_cmd = ft_strsub(second_cmd, 1, ft_strlen(second_cmd) - 1);
		second_cmd = ft_cut_withspace(second_cmd);
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 2));
	}
	else
	{
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, NULL, M_READ, 0));
	}
}
