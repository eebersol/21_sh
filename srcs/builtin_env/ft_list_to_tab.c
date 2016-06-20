/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:16 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char	**ft_list_to_tab(t_list **list)
{
	t_env	*env;
	t_list	*cur;
	char	**tab_env;
	int		i;

	cur = *list;
	i = 0;
	tab_env = (char**)malloc(sizeof(char*) * (ft_lstlen(*list) + 1));
	while (cur)
	{
		env = cur->content;
		if (env->var)
			tab_env[i] = ft_strjoin(env->var, "=");
		if (env->value)
			tab_env[i] = ft_strjoin(tab_env[i], env->value);
		i++;
		cur = cur->next;
	}
	tab_env[i] = NULL;
	return (tab_env);
}
