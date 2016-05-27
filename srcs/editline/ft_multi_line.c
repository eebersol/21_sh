/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_jump_line(void)
{
	t_sh 		*sh;
	t_prompt	*prompt;
	t_window	window;

	sh = ft_sh();
	prompt = sh->prompt;
	window = sh->window;
	prompt->y = (prompt->x / sh->window.col) + 1;
	if ((prompt->x + 3) == window.col * prompt->y)
	{
		tputs(tgoto((tgetstr("do", NULL)), 0, 0), 0, tputs_putchar);
		prompt->y++;
		prompt->x++;
		prompt->index++;
		return (1);
	}
	return (0);
}
