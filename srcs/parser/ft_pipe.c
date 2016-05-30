/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                              		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/09 17:23:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static 
void	ft_pipe(char **cmd, char **env)
{
	t_sh 		*sh;
	t_prompt	*promt;
	char 		**cmd;
	char 		**db_tab;
	int			pfd[2];
	int 		pid;

	sh = ft_sh();
	prompt = sh->prompt;
	ft_create_tab(cmd);
	if (pipe(pfd) == -1)
		printf("21sh : Pipe fail\n");
	else if ((pid = fork()) < 0)
		printf("21sh : Fork failed\n");
	else if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close (pfd[0]);
		execve(cmd[0], cmd, sh->env)
		printf("21sh : Wc failed\n");
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve(next_cmd[0], next_cmd, sh->env);
	}
	return ;
}