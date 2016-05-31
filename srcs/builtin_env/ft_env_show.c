/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:35 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:36 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_env_show(t_list *list)
{
	t_env	*env;
	t_list	*cur;

	cur = list;
	while (cur)
	{
		env = cur->content;
		ft_putstr(env->var);
		ft_putstr("=");
		ft_putendl(env->value);
		cur = cur->next;
	}
}
