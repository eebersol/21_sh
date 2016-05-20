/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:04 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:07 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static t_list		*ft_match_node(t_list *cur,
											t_list **list, char **cmd, int j)
{
	t_env	*env;
	int		i;

	i = 0;
	while (cur)
	{
		env = cur->content;
		if (ft_strcmp(env->var, cmd[j]) == 0)
		{
			ft_lstdel_at(list, i, &ft_free_node);
			if (i == 1)
				*list = cur->next;
			return (*list);
		}
		else
			cur = cur->next;
		i++;
	}
	return (*list);
}

t_list				*ft_env_unset(t_list **list, char **cmd)
{
	t_list	*cur;
	int		j;

	j = 1;
	cur = *list;
	while (cmd[j])
	{
		cur = ft_match_node(cur, list, cmd, j);
		if (cmd[j + 1] == NULL)
			break ;
		j++;
	}
	return (*list);
}
