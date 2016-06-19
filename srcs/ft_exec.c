/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/09 17:23:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	char		**db_tab;
	char		**cmd;
	int			i;

	sh = ft_sh();
	i = 0;
	prompt = sh->prompt;
	db_tab = ft_strsplit(prompt->complet_prompt, ';');
	while (i < ft_tab_len(db_tab))
	{
		cmd = ft_word_to_tab(db_tab[i]);
		if (cmd[0])
			minishell_exec(sh->env, cmd);
		i++;
	}
}

int		ft_exec(char **cmd, char **env)
{
	pid_t	pid;
	int		status;
	int		flag;

	flag = 0;
	if ((pid = fork()) == 0)
	{
		if ((execve(cmd[0], cmd, env)) != -1)
			flag = -1;
		else
			exit(0);
		flag = 1;
	}
	wait(&status);
	return (flag);
}
