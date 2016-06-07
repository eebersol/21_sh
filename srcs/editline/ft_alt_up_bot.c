/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt_up_bot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static	void	ft_is_last_li(t_prompt *prompt, t_window window)
{
	if (prompt->x % window.col < window.li)
	{
		tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
		prompt->index = prompt->x + window.col;
		prompt->x = window.col - prompt->x;
		prompt->count = (window.col * prompt->y) - prompt->x;
		prompt->x += prompt->count - 2;
		while (prompt->x < prompt->index)
		{
			prompt->x++;
			tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
		}
		prompt->index = prompt->x;
		prompt->count = 0;
	}
}

static void		ft_is_moving(t_prompt *prompt, t_window	window)
{
	tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
	prompt->index = prompt->x + window.col;
	prompt->x = window.col - prompt->x;
	prompt->count = (window.col * prompt->y) - prompt->x;
	prompt->x += prompt->count - 2;
	while (prompt->x < prompt->index)
	{
		prompt->x++;
		tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
	}
	prompt->index = prompt->x;
	prompt->count = 0;
}

void		ft_alt_up(void)
{
	t_sh		*sh;
	t_window	window;

	sh = ft_sh();
	window = sh->window;
	sh->prompt->y = ((sh->prompt->x + 3) / sh->window.col) + 1;
	if (sh->prompt->y == 2 && sh->prompt->x < window.col)
	{
		tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
		if (sh->prompt->x < window.col - 1)
			sh->prompt->x = -2;
		else
			sh->prompt->x = -1;
		while (sh->prompt->x++ < 0)
			tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
		sh->prompt->y = 1;
	}
	else if (sh->prompt->y != 1)
	{
		tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
		sh->prompt->x -= window.col;
		sh->prompt->y--;
	}
	sh->prompt->index = sh->prompt->x;
}

void		ft_alt_down(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_window	window;

	sh = ft_sh();
	prompt = sh->prompt;
	window = sh->window;
	prompt->y = ((prompt->x + 3) / sh->window.col) + 1;
	prompt->max_li = ft_lstlen(prompt->l_char) / window.col;
	window.li = ft_lstlen(prompt->l_char) - (((window.col) *
		(ft_lstlen(prompt->l_char) / window.col)));
	window.li += 2;
	if (prompt->y == (ft_lstlen(prompt->l_char)) / (window.col) + 1)
		return ;
	else if (prompt->y == prompt->max_li)
		ft_is_last_li(prompt, window);
	else
		ft_is_moving(prompt, window);
}
