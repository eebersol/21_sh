/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:49:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/30 19:49:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_resize_window(void)
{
	t_sh		*sh;
	t_window	window;

	sh = ft_sh();
	window = sh->window;
	if (ioctl(0, TIOCGWINSZ, window.win) != -1)
	{
		ft_get_col_li();
		ft_list_show(sh->prompt->l_char);
	}
}
