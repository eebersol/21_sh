/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static int	ft_check_redir(char *str)
{
	int i;
	int	j;

	i = ft_strlen(str);
	j = 0;
	while (j < i)
	{
		if (str[j] == '>' && str[j + 1] == '>' && str[j - 1] != '2')
			return (1);
		else if (str[j] == '<' && str[j + 1] == '<')
			return (2);
		else if (str[j] == '>' && str[j + 1] != '>' && str[j - 1] == '2')
			return (3);
		else if (str[j] == '>' && str[j + 1] == '>' && str[j - 1] == '2')
			return (4);
		else if (str[j] == '1' && str[j + 1] == '>' && str[j + 2] == '&'
			&& str[j + 3] == '2')
			return (5);
		j++;
	}
	return (0);
}

char		*ft_get_opt(char *str)
{
	char		*b;
	static char	*opt;
	char		*tmp;
	char		*salut;
	char		*content;

	content = NULL;
	tmp = NULL;
	b = ft_strnew(1);
	ft_putstr("heredoc> ");
	while (read(0, b, 1))
	{
		ft_putchar(b[0]);
		content = ft_strdup(ft_freejoin(content, b));
		if (ENTER)
		{
			content = ft_strtrim(content);
			if (ft_strcmp(content, str) == 0)
			{
				tmp = ft_strdup(opt);
				return (tmp);
			}
			else
			{
				opt = ft_strdup(ft_freejoin(opt, content));
				opt = ft_strdup(ft_freejoin(opt, ","));
				ft_get_opt(str);
			}
			salut = ft_strdup(opt);
			return (salut);
		}
	}
	return (" ");
}

t_cmd		*ft_parse_cmd(char *str)
{
	char	*begin_cmd;
	char	*second_cmd;
	char	*p_str;
	char	*test;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	second_cmd = ft_strnew(1);
	p_str = ft_strnew(1);
	begin_cmd = ft_cut_withspace(str);
	while (i < j && str[i] != '|' && str[i] != '<' && str[i] != '>')
		i++;
	if ((ft_strsub(str, (i + 1), ((i - j) * -1))) != NULL)
		second_cmd = ft_right_body(ft_strsub(str, (i + 1), ((i - j) * -1)));
	if ((*p_str = ft_strchr(str, '>') != NULL) && ft_check_redir(str) == 0)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 1));
	}
	else if ((*p_str = ft_strchr(str, '>') != NULL) && ft_check_redir(str) == 1)
	{
		second_cmd = ft_strsub(second_cmd, 1, ft_strlen(second_cmd) - 1);
		second_cmd = ft_cut_withspace(second_cmd);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 1));
	}
	else if ((*p_str = ft_strchr(str, '<') != NULL) && ft_check_redir(str) == 0)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		return (ft_build_redirection(begin_cmd, second_cmd, M_READ_APPEND, 0));
	}
	else if ((*p_str = ft_strchr(str, '<') != NULL) && ft_check_redir(str) == 2)
	{
		second_cmd = ft_strsub(second_cmd, 1, ft_strlen(second_cmd) - 1);
		second_cmd = ft_cut_withspace(second_cmd);
		test = ft_get_opt(second_cmd);
		return (ft_build_heredoc(begin_cmd, test));
	}
	else if (ft_check_redir(str) == 3)
	{
		second_cmd = ft_cut_withspace(second_cmd);
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_TRUNC, 2));
	}
	else if (ft_check_redir(str) == 4)
	{
		second_cmd = ft_strsub(second_cmd, 1, ft_strlen(second_cmd) - 1);
		second_cmd = ft_cut_withspace(second_cmd);
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, second_cmd, M_WRITE_APPEND, 2));
	}
	else if (ft_check_redir(str) == 5)
	{
		begin_cmd = ft_strsub(begin_cmd, 0, ft_strlen(begin_cmd) - 1);
		return (ft_build_redirection(begin_cmd, NULL, M_READ, 0));
	}
	else if (ft_strchr(str, '|'))
		return (ft_build_pipe(begin_cmd, second_cmd));
	else
		return (ft_build_exec(begin_cmd));
}

void	ft_main_parser(void)
{
	t_sh			*sh;
	t_cmd			*cmd;
	static	int		i = 0;
	char			**split;

	sh = ft_sh();
	split = ft_strsplit(sh->prompt->complet_prompt, ';');
	cmd = ft_parse_cmd(split[i]);
	ft_exec_cmd(cmd);
	if (i < ft_tab_len(split) - 1)
		i++;
	else
		i = 0;
}
