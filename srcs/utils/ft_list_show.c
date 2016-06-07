/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_list_shower(t_list *list, t_prompt *prompt)
{
	t_list	*cur;
	char	c;
	int		i;

	i = 0;
	cur = list;
	while (i < prompt->index)
	{
		cur = cur->next;
		i++;
	}
	while (cur)
	{
		c = *((char *)cur->content);
		ft_putchar(c);
		cur = cur->next;
	}
}

void	ft_list_show(t_list *list)
{
	char	c;
	t_list	*cur;

	cur = list;
	while (cur)
	{
		c = *((char *)cur->content);
		ft_putchar(c);
		cur = cur->next;
	}
}
