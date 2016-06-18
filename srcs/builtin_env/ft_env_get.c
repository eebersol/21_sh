/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:24 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char	*ft_env_get(t_list *list, char *var)
{
	t_list	*cur;
	t_env	*env;

	cur = list;
	while (cur)
	{
		env = cur->content;
		if (ft_strcmp(env->var, var) == 0)
			return (env->value);
		cur = cur->next;
	}
	return ("");
}
