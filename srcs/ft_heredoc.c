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


void		manage_double_read(t_cmd *cmd, t_sh *sh, char *str)
{
	int		p[2];
	pid_t	pid;
	int		status;
	t_pipe	*p_cmd;


	sh = ft_sh();
	p_cmd = (t_pipe*)cmd;
	if (pipe(p) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(p[1], 1);
			close(p[0]);
			parse_heredoc_redir(str);
		}
		else
		{
			dup2(p[0], 0);
			close(p[1]);
			waitpid(-1, &status, 0);
			ft_exec_cmd(p_cmd->left, sh->env)
		}
	}
	else
		exit(2);
}