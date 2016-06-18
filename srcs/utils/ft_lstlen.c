/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:36:49 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 19:36:50 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		ft_lstlen(t_list *list)
{
	int		i;
	t_env	*env;

	i = 0;
	while (list)
	{
		env = list->content;
		list = list->next;
		i++;
	}
	return (i);
}
