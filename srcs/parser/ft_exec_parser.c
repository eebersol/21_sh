/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_exec_pipe(t_cmd *cmd)
{
	t_pipe	*p_cmd;
	int		pipes[2];
	int		pid[2];

	p_cmd = (t_pipe*)cmd;
	if (pipe(pipes) != 0)
		ft_putendl_fd("pipe error", 2);
	else if ((pid[0] = fork()) == 0)
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		ft_exec_cmd(p_cmd->left);
		exit(0);
	}
	if ((pid[1] = fork()) == 0)
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		ft_exec_cmd(p_cmd->right);
		exit(0);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

int		ft_exec_cmd(t_cmd *cmd)
{
	t_sh   *sh;
	t_pipe *pipe;
	t_exec *exec;
	char 	**tmp_env;
	int 	ret;

	sh = ft_sh();
	ret = 1;
	if (cmd->type == PIPE)
	{
		pipe = (t_pipe*)cmd;
		ft_exec_pipe(cmd);
	}
/*	else if (cmd->type == REDIRECTION)
	{
		redirecton = (t_redirection*)cmd;
		ft_exec_redirection();
	}*/
	else if (cmd->type == EXEC)
	{
		exec = (t_exec*)cmd;
		tmp_env = ft_list_to_tab(&sh->env);
		if (ft_get_path(sh->env, exec->opt[0]) != NULL)
			exec->opt[0] = ft_get_path(sh->env, exec->opt[0]);
		else
			ft_error_not_found(exec->opt[0]);
		ft_exec(exec->opt, tmp_env);
	}
	else
		ret = 0;
	return (ret);
}