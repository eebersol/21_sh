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

#include <shell.h>

void	ft_list_shower(t_list *list, t_prompt *prompt)
{
	t_list	*cur;
	char	c;
	int		i;

	i = 0;
	cur = list;
	while (i < prompt->x)
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
	t_sh	*sh;
	t_list	*cur;

	cur = list;
	sh = ft_sh();
	sh->prompt->x = 0;
	while (cur)
	{
		c = *((char *)cur->content);
		ft_putchar(c);
		sh->prompt->x++;
		cur = cur->next;
	}
	sh->prompt->index = sh->prompt->x;
}

void	ft_list_show_to(t_list *list)
{
	t_sh	*sh;
	t_list	*cur;

	sh = ft_sh();
	cur = list;
	sh->prompt->x = 0;
	while (cur)
	{
		ft_putendl_fd(cur->content, 1);
		cur = cur->next;
	}
	sh->prompt->index = sh->prompt->x;
}
