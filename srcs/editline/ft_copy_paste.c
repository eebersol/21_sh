/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_paste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_cuting(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*cur;
	int			i;
	int			j;

	sh = ft_sh();
	prompt = sh->prompt;
	j = prompt->x;
	i = prompt->x - prompt->cut_len;
	cur = prompt->l_char;
	ft_clean_prompt();
	while (j-- > i)
	{
		cur = prompt->l_char;
		ft_lstdel_at(&cur, j, &ft_free_node);
	}
	cur = prompt->l_char;
	tputs(tgoto((tgetstr("me", NULL)), 0, 0), 0, tputs_putchar);
	ft_list_show(cur);
	tputs(tgoto((tgetstr("rc", NULL)), 0, 0), 0, tputs_putchar);
	prompt->x = j + 1;
	prompt->copy_mode = 0;
	prompt->index = prompt->x;
}

void	ft_copying(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*cur;
	char		c;

	sh = ft_sh();
	prompt = sh->prompt;
	cur = prompt->l_char;
	if (prompt->copy_mode == 1)
	{
		cur = ft_lstget_at(cur, prompt->x);
		prompt->str_cpy = ft_strdup(ft_freejoin(prompt->str_cpy,
			(char*)cur->content));
		tputs(tgoto((tgetstr("mr", NULL)), 0, 0), 0, tputs_putchar);
		c = *((char *)cur->content);
		ft_putchar(c);
		prompt->cut_len++;
	}
}

void	ft_paste(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	char		c;
	size_t		i;

	sh = ft_sh();
	i = 0;
	prompt = sh->prompt;
	while (i < ft_strlen(prompt->str_cpy))
	{
		c = prompt->str_cpy[i];
		ft_lstadd_at(&prompt->l_char,
			ft_lstnew(&c, sizeof(char)), prompt->x + i);
		i++;
	}
	prompt->x_copy = prompt->x;
	tputs(tgoto((tgetstr("sc", NULL)), 0, 0), 0, tputs_putchar);
	ft_clean_prompt();
	ft_list_show(prompt->l_char);
	tputs(tgoto((tgetstr("rc", NULL)), 0, 0), 0, tputs_putchar);
	prompt->x = prompt->x_copy;
	prompt->index = prompt->x;
}

void	ft_copy(void)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (prompt->copy_mode == 1)
	{
		tputs(tgoto((tgetstr("me", NULL)), 0, 0), 0, tputs_putchar);
		prompt->copy_mode = 0;
	}
	else
		prompt->copy_mode = 1;
}

void	ft_copy_paste_cut(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (A_C)
		ft_copy();
	else if (A_V)
		ft_paste();
	else if (A_X)
	{
		if (prompt->copy_mode == 0)
		{
			tputs(tgoto((tgetstr("sc", NULL)), 0, 0), 0, tputs_putchar);
			ft_copy();
		}
		else if (prompt->copy_mode == 1)
			ft_cuting();
	}
}
