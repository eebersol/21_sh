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

int		ft_chkrdir(char *s1)
{
	int i;
	int	j;

	i = ft_strlen(s1);
	j = 0;
	while (j < i)
	{
		if (s1[j] == '>' && s1[j + 1] == '>' && s1[j - 1] != '2')
			return (1);
		else if (s1[j] == '<' && s1[j + 1] == '<')
			return (2);
		else if (s1[j] == '>' && s1[j + 1] != '>' && s1[j - 1] == '2')
			return (3);
		else if (s1[j] == '>' && s1[j + 1] == '>' && s1[j - 1] == '2')
			return (4);
		else if (s1[j] == '1' && s1[j + 1] == '>' && s1[j + 2] == '&'
			&& s1[j + 3] == '2')
			return (5);
		j++;
	}
	return (0);
}

t_list	*ft_get_opt(char *s1)
{
	char		*b;
	t_list		*list;
	char		*content;

	content = NULL;
	b = ft_strnew(1);
	list = NULL;
	ft_putstr("heredoc> ");
	while (read(0, b, 1))
	{
		ft_putchar(b[0]);
		content = ft_strtrim(ft_freejoin(content, b));
		if (ENTER)
		{
			if (ft_strcmp(content, s1) == 0)
				break ;
			else
			{
				ft_lstadd(&list, ft_lstnew(content, ft_strlen(content)));
				ft_putstr("heredoc> ");
				content = ft_strnew(1);
			}
		}
	}
	return (list);
}

t_cmd	*ft_parse_cmd(char *s1)
{
	char		*begin_cmd;
	char		*second_cmd;
	char		*p_s1;
	size_t		i;

	i = 0;
	second_cmd = ft_strnew(1);
	p_s1 = ft_strnew(1);
	begin_cmd = ft_cut_withspace(s1);
	while (i < (ft_strlen(s1)) && s1[i] != '|' && s1[i] != '<' && s1[i] != '>')
		i++;
	if ((ft_strsub(s1, (i + 1), ((i - (ft_strlen(s1))) * -1))) != NULL)
		second_cmd = ft_right_body(ft_strsub(s1, i + 1, ((i - ft_strlen(s1) * -1))));
	if (((*p_s1 = ft_strchr(s1, '>') != NULL) && ft_chkrdir(s1) == 1) ||
				((*p_s1 = ft_strchr(s1, '>') != NULL) && ft_chkrdir(s1) == 0))
		return (ft_parse_redir_left(s1, begin_cmd, second_cmd));
	else if (((*p_s1 = ft_strchr(s1, '<') != NULL) && ft_chkrdir(s1) == 2) ||
				((*p_s1 = ft_strchr(s1, '<') != NULL) && ft_chkrdir(s1) == 0))
		return (ft_parse_redir_right(s1, begin_cmd, second_cmd));
	else if (ft_chkrdir(s1) == 3 || ft_chkrdir(s1) == 4 || ft_chkrdir(s1) == 5)
		return (ft_parse_redir_error(s1, begin_cmd, second_cmd));
	else if (ft_strchr(s1, '|'))
		return (ft_build_pipe(begin_cmd, second_cmd));
	else
		return (ft_build_exec(begin_cmd));
}

void	ft_main_parser(void)
{
	t_sh			*sh;
	t_cmd			*cmd;
	int				i;
	char			**split;

	sh = ft_sh();
	i = 0;
	split = ft_strsplit(sh->prompt->complet_prompt, ';');
	while (i < ft_tab_len(split))
	{
		cmd = ft_parse_cmd(split[i]);
		ft_exec_cmd(cmd);
		i++;
	}
}
