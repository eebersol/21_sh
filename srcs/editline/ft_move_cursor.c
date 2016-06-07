/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_arrow_left(void)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (prompt->copy_mode == 1 && prompt->x > 0)
	{
		ft_copying();
		prompt->index--;
		prompt->x--;
	}
	else if (prompt->x > 0)
	{
		prompt->index--;
		prompt->x--;
		tputs(tgoto((tgetstr("le", NULL)), 0, 0), 0, tputs_putchar);
	}
}

void	ft_arrow_right(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_window	window;

	sh = ft_sh();
	prompt = sh->prompt;
	window = sh->window;
	if (prompt->copy_mode == 1 && prompt->x < prompt->lenght)
	{
		ft_copying();
		prompt->index++;
		prompt->x++;
	}
	else if (ft_jump_line() == 0)
	{
		if (prompt->x < (ft_lstlen(prompt->l_char)))
		{
			prompt->index++;
			prompt->x++;
			tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
		}
	}
}

void	ft_move_cursor(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (LEFT)
		ft_arrow_left();
	else if (RIGHT)
		ft_arrow_right();
	else if (TOP && ft_lstlen(prompt->history) > 0)
		ft_move_top();
	else if (BOT && ft_lstlen(prompt->history) != 0)
		ft_move_bot();
}
