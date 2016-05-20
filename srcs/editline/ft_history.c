/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_move_top(void)
{
	t_sh *sh;
	t_prompt *prompt;
	t_list 	*list;

	sh = ft_sh();
	prompt = sh->prompt;
	list = prompt->history;
	ft_lstdel(&prompt->l_char, &ft_free_node);
	if (prompt->first_process == 0)
	{
		prompt->index_history = ft_lstlen(list) - 1;
		prompt->first_process = 1;
		ft_clean_prompt();
		list = ft_lstget_at(list, prompt->index_history);
		ft_putstr((char*)list->content);
		ft_history_to_lchar(list->content);
	}
	else
	{
		list = prompt->history;
		list = ft_lstget_at(list, prompt->index_history);
		ft_clean_history((char*)list->content);
		prompt->index_history--;
		if (prompt->index_history < 0)
			prompt->index_history = ft_lstlen(list) - 1;
		list = prompt->history;
		list = ft_lstget_at(list, prompt->index_history);
		ft_putstr((char*)list->content);
		ft_history_to_lchar(list->content);
	}
	prompt->x = ft_strlen((char*)list->content);
	prompt->index = prompt->x;
}

void	ft_move_bot(void)
{
	t_sh *sh;
	t_prompt *prompt;
	t_list	*cur;

	sh = ft_sh();
	prompt = sh->prompt;
	cur = prompt->history;
	ft_lstdel(&prompt->l_char, &ft_free_node);
	if (prompt->first_process == 0)
		return ;
	else
	{
		cur = prompt->history;
		cur = ft_lstget_at(cur, prompt->index_history);
		ft_clean_history((char*)cur->content);
		prompt->index_history++;
		if (prompt->index_history > ft_lstlen(cur) - 1)
			prompt->index_history = 0;
		cur = ft_lstget_at(prompt->history, prompt->index_history);
		ft_putstr(cur->content);
		ft_history_to_lchar(cur->content);
		prompt->x = ft_strlen((char*)cur->content);
		prompt->index = prompt->x;
	}
}

void	ft_add_to_history(char *str)
{
	t_sh *sh;;
	t_prompt *prompt;
	t_list 	*new;

	sh = ft_sh();
	prompt = sh->prompt;
	new = ft_lstnew(str, sizeof(char *) * ft_strlen(str));
	ft_lstadd_at(&prompt->history, new, prompt->index_history);
	prompt->index_history++;
}

void	ft_history(void)
{
	ft_add_to_history(ft_list_to_string());
}
