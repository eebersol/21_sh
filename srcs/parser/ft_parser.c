/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser .c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static int	parse_heredoc_redir(char *target)
{
	t_sh 	*sh;
	int		pipe_fd[2];
	char	*line;

	sh = ft_sh();
	pipe_fd[0] = 0;
	pipe(pipe_fd);
	line = "";
	ft_term_reset(sh);
	while (ft_strcmp(line, target))
	{
		ft_putstr("heredoc>> ");
		if (get_next_line(0, &line) < 1)
			break ;
		if (line && ft_strcmp(line, target))
		{
			write(pipe_fd[1], line, ft_strlen(line));
			write(pipe_fd[1], "\n", 1);
			free(line);
		}
	}
	close(pipe_fd[1]);
	return (0);
}

static int	ft_check_redir(char *str)
{
	int i;
	int	j;

	i = ft_strlen(str);
	j = 0;
	while (j < i)
	{
		if (str[j] == '>' && str[j + 1] == '>')
			return (1);
		else if (str[j] == '<' && str[j + 1] == '<')
			return (2);
		j++;
	}
	return (0);
}

t_cmd	*ft_parse_cmd(char *str)
{
	char 				*begin_cmd;
	char				*second_cmd;
	char 				*p_str;
	//char 				*test;
	int 				i;
	int					j;

	i = 0;
	j = ft_strlen(str);
	second_cmd = ft_strnew(1);
	p_str = ft_strnew(1);
	begin_cmd = ft_cut_withspace(str);
	while (i < j && str[i] != '|' && str[i] != '<' && str[i] != '>')
		i++;
	if ((ft_strsub(str, (i + 1), ((i - j) * - 1))) != NULL)
		second_cmd = ft_right_body(ft_strsub(str, (i + 1), ((i - j) * - 1)));
	if (ft_strchr(str, '|'))
		return (ft_build_pipe(begin_cmd, second_cmd));
	else if ((*p_str = ft_strchr(str, '>') != NULL) && ft_check_redir(str) == 0)
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
		parse_heredoc_redir(second_cmd);
		//test = ft_get_opt(second_cmd);
		//begin_cmd = ft_strjoin(begin_cmd, " ");
		//test = ft_strdup(ft_strjoin(begin_cmd, test));
		//printf("tt %s\n", test);
		return (ft_build_redirection(begin_cmd, NULL, M_READ_APPEND, 0));
	}
	else
		return (ft_build_exec(begin_cmd));
}

void	ft_main_parser(void)
{	
	t_sh *sh;
	t_cmd *cmd;
	static	int 	i = 0;
	char 	**split;

	sh = ft_sh();
	split = ft_strsplit(sh->prompt->complet_prompt, ';');
	cmd = ft_parse_cmd(split[i]);
	ft_exec_cmd(cmd);
	if (i < ft_tab_len(split) - 1)
		i++;
	else
		i = 0;
}