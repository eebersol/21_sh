/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_col_li.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_get_col_li(void)
{
	t_sh *sh;
	t_window 	*window;

	sh = ft_sh();
	window = &sh->window;
	if (window->win_count == 0)
	{
		window->col = (tgetnum("co"));
		window->li = tgetnum("li");
	}
	else if (window->win_count != 0)
	{
		window->col = window->win.ws_col;
		window->li = window->win.ws_row;
	}
}

