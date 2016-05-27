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

void	ft_alt_up(void)
{
	t_sh *sh;
	t_prompt *prompt;
	t_window window;

	sh = ft_sh();
	prompt = sh->prompt;
	window = sh->window;
	prompt->y = ((prompt->x + 3) / sh->window.col) + 1;
	if (prompt->y == 2 && prompt->x < window.col)
	{
		tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
		if (prompt->x < window.col - 1)
			prompt->x = -2;
		else
			prompt->x = -1;
		while (prompt->x++ < 0)
			tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
		prompt->y = 1;
	}
	else
	{
		tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
		prompt->x -= window.col;
		prompt->y--;
	}
	prompt->index = prompt->x;
}

void 	ft_alt_down(void)
{
	t_sh *sh;
	t_prompt *prompt;
	t_window window;

	sh = ft_sh();
	prompt = sh->prompt;
	window = sh->window;
	prompt->y = ((prompt->x + 3) / sh->window.col) + 1;
	prompt->max_li = ft_lstlen(prompt->l_char) / window.col;
	window.li = ft_lstlen(prompt->l_char) - (((window.col) * (ft_lstlen(prompt->l_char) / window.col)));
	window.li += 2;
	if (prompt->y == (ft_lstlen(prompt->l_char)) / (window.col) + 1)
		return ;
	else if (prompt->y == prompt->max_li)
	{
		if (prompt->x % window.col < window.li)
		{
			tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
			prompt->index = prompt->x + window.col;
			prompt->x = window.col - prompt->x ;
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
	else
	{
		tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
		prompt->index = prompt->x + window.col;
		prompt->x = window.col - prompt->x ;
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