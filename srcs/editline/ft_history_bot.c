/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	void	ft_basic_bot(t_prompt *prompt, t_list *cur)
{
	cur = prompt->history;
	cur = ft_lstget_at(cur, prompt->index_history);
	ft_lstdel(&prompt->l_char, &ft_free_node);
	ft_history_to_lchar(cur->content);
	ft_clean_history((char*)cur->content);
	prompt->index_history++;
	if (prompt->index_history == ft_lstlen(prompt->history))
		prompt->index_history = 0;
	cur = prompt->history;
	cur = ft_lstget_at(prompt->history, prompt->index_history);
	prompt->x = ft_strlen((char*)cur->content);
	prompt->index = prompt->x;
	ft_putstr(cur->content);
	ft_lstdel(&prompt->l_char, &ft_free_node);
	ft_history_to_lchar(cur->content);
}

void			ft_move_bot(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*cur;

	sh = ft_sh();
	prompt = sh->prompt;
	cur = prompt->history;
	ft_lstdel(&prompt->l_char, &ft_free_node);
	if (prompt->first_process == 0)
		return ;
	else
		ft_basic_bot(prompt, cur);
}
