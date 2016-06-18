/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	void	ft_basic_top(t_prompt *prompt, t_list *list)
{
	list = prompt->history;
	list = ft_lstget_at(list, prompt->index_history);
	ft_lstdel(&prompt->l_char, &ft_free_node);
	ft_history_to_lchar(list->content);
	ft_clean_history((char*)list->content);
	prompt->index_history--;
	if (prompt->index_history < 0)
		prompt->index_history = ft_lstlen(list) - 1;
	list = prompt->history;
	list = ft_lstget_at(prompt->history, prompt->index_history);
	prompt->x = ft_strlen((char*)list->content);
	prompt->index = prompt->x;
	ft_putstr((char*)list->content);
	ft_lstdel(&prompt->l_char, &ft_free_node);
	ft_history_to_lchar(list->content);
}

static	void	ft_first_move_top(t_prompt *prompt, t_list *list)
{
	prompt->index_history = ft_lstlen(list) - 1;
	prompt->first_process = 1;
	ft_clean_prompt();
	list = ft_lstget_at(list, prompt->index_history);
	prompt->x = ft_strlen((char*)list->content);
	ft_putstr((char*)list->content);
	ft_lstdel(&prompt->l_char, &ft_free_node);
	ft_history_to_lchar((char*)list->content);
	prompt->index = prompt->x;
}

void			ft_move_top(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*list;

	sh = ft_sh();
	prompt = sh->prompt;
	list = prompt->history;
	ft_lstdel(&prompt->l_char, &ft_free_node);
	if (prompt->first_process == 0)
		ft_first_move_top(prompt, list);
	else
		ft_basic_top(prompt, list);
}
