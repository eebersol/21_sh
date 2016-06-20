/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fn_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_exec_simple_cmd(t_cmd *cmd)
{
	t_exec	*exec;
	char	**tmp_env;
	char	*s1;
	t_sh	*sh;

	sh = ft_sh();
	exec = (t_exec*)cmd;
	s1 = ft_strdup(exec->opt[0]);
	tmp_env = ft_list_to_tab(&sh->env);
	if (sh->prompt->copy_mode == 1)
		tputs(tgoto((tgetstr("me", NULL)), 0, 0), 0, tputs_putchar);
	if (!exec->opt[0] || !exec->opt)
		return ;
	if (((ft_strcmp(s1, "cd")) == 0) || (s1[0] == '!') ||
		((ft_strcmp(s1, "setenv")) == 0) || ((ft_strcmp(s1, "unsetenv")) == 0)
		|| ((ft_strcmp(s1, "exit")) == 0) || ((ft_strcmp(s1, "env")) == 0)
		|| (s1[0] == '.' && s1[1] == '/') || ((ft_strcmp(s1, "help")) == 0))
		minishell_exec(sh->env, exec->opt);
	else if (ft_get_path(sh->env, exec->opt[0]) != NULL)
	{
		exec->opt[0] = ft_get_path(sh->env, exec->opt[0]);
		ft_exec(exec->opt, tmp_env);
	}
	else
		ft_error_not_found(exec->opt[0]);
}
