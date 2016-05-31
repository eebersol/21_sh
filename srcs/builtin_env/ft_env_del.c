/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:33:50 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/14 18:33:51 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_env_del(t_list **list)
{
	t_list	*cur;
	t_env	*env;

	cur = *list;
	env = cur->content;
	while (cur)
	{
		env = cur->content;
		ft_strdel(&(env->var));
		ft_strdel(&(env->value));
		free(env);
		cur = cur->next;
	}
	return (0);
}
