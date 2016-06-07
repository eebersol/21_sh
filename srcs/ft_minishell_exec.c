/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/09 17:23:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	minishell_exec(t_list *env, char **cmd)
{
	t_sh		*sh;
	t_prompt	*prompt;
	char		*varname;
	char		**tab_env;

	varname = cmd[0];
	sh = ft_sh();
	prompt = sh->prompt;
	tab_env = ft_list_to_tab(&env);
	if ((ft_strcmp(cmd[0], "cd")) == 0)
		ft_cd(env, cmd);
	else if ((ft_strcmp(cmd[0], "env")) == 0)
		ft_env_opt(env, cmd);
	else if ((ft_strcmp(cmd[0], "setenv")) == 0)
	{
		if ((ft_error_set_unset_env(cmd, "setenv")) == 0)
			ft_env_set(&env, cmd[1], cmd[2]);
	}
	else if ((ft_strcmp(cmd[0], "unsetenv")) == 0)
		*env = *ft_env_unset(&env, cmd);
	else if ((ft_strcmp(cmd[0], "exit")) == 0)
		ft_exit(cmd, &env);
	else if ((cmd[0][0] == '.' && cmd[0][1] == '/') || cmd[0][0] == '/')
		ft_exec(cmd, tab_env);
	else if (1)
	{
		ft_main_parser();
	}
}