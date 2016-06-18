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

#include <shell.h>

static	void	ft_up_bis(t_sh *sh, t_window window)
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

static void		ft_is_moving(t_prompt *prompt, t_window window)
{
	int i;

	prompt->index = prompt->x;
	prompt->index += window.col;
	if (prompt->index > ft_lstlen(prompt->l_char))
		return ;
	else
	{
		i = 0;
		tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
		prompt->count = window.col - prompt->x;
		prompt->x += prompt->count;
		prompt->count = prompt->index - (window.col * prompt->y) + 4;
	}
	while (i < prompt->count)
	{
		tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
		i++;
	}
	prompt->count = 0;
	prompt->x = prompt->index;
}

void			ft_alt_up(void)
{
	t_sh		*sh;
	t_window	window;

	sh = ft_sh();
	window = sh->window;
	sh->prompt->index = sh->prompt->x;
	sh->prompt->y = ((sh->prompt->x + 3) / window.col) + 1;
	if ((sh->prompt->y == 1) ||
		(sh->prompt->index > (window.col - 4)
			&& sh->prompt->index < window.col))
		return ;
	else if (sh->prompt->y == 2 && sh->prompt->x < window.col)
		ft_up_bis(sh, window);
	else if (sh->prompt->y != 1)
	{
		tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
		sh->prompt->x -= window.col;
		sh->prompt->y--;
	}
	sh->prompt->index = sh->prompt->x;
}

void			ft_alt_down(void)
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
	else
		ft_is_moving(prompt, window);
}
