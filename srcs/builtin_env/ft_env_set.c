/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:55:56 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:55:58 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_env_set(t_list **list, char *var, char *value)
{
	t_list	*cur;
	t_env	*env;

	cur = *list;
	while (cur)
	{
		env = cur->content;
		if (ft_strcmp(env->var, var) == 0)
		{
			if (value)
				env->value = ft_strdup(value);
			else
				env->value = ft_strnew(0);
			return ;
		}
		cur = cur->next;
	}
	if ((env = (t_env*)malloc(sizeof(t_env*))) != NULL)
	{
		if (var)
			env->var = ft_strdup(var);
		if (value)
			env->value = ft_strdup(value);
		ft_lstadd_back(list, ft_lstnew(env, sizeof(t_env)));
	}
}
