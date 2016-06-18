/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:40 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:42 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static t_env	ft_init_node(int j, int i, char **cmd)
{
	t_env env;

	env.var = ft_strnew(j + 1);
	ft_strncpy(env.var, cmd[i], j);
	env.var[j] = 0;
	env.value = ft_strsub(cmd[i], j + 1,
		ft_strlen(ft_strchr(cmd[i], '=')));
	return (env);
}

static void		ft_exec_env(char **cmd, t_list *list, t_list *new_list, int i)
{
	if (cmd[i])
		minishell_exec(list, &cmd[i]);
	else
		ft_env_show(new_list);
}

void			ft_env_copy(t_list **new, t_list *list)
{
	t_list	*cur;
	t_env	env;

	cur = list;
	while (cur)
	{
		if (!(((t_env *)cur->content)->var))
			env.var = NULL;
		else
			env.var = ft_strdup(((t_env *)cur->content)->var);
		if (!(((t_env *)cur->content)->value))
			env.value = NULL;
		else
			env.value = ft_strdup(((t_env *)cur->content)->value);
		ft_lstadd_back(new, ft_lstnew(&env, sizeof(t_env)));
		cur = cur->next;
	}
}

void			ft_env_opt(t_list *list, char **cmd)
{
	t_list	*new_list;
	t_env	env;
	int		i;
	int		j;

	new_list = NULL;
	if (cmd[1] && ft_strcmp(cmd[1], "-i") == 0)
		i = 2;
	else
	{
		i = 1;
		ft_env_copy(&new_list, list);
	}
	j = 0;
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		j = ft_cut_title(cmd[i]);
		env = ft_init_node(j, i, cmd);
		ft_env_set(&new_list, env.var, env.value);
		i++;
	}
	ft_exec_env(cmd, list, new_list, i);
}
