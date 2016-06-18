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

#include <shell.h>

void	ft_resize_window(void)
{
	t_sh		*sh;

	sh = ft_sh();
	if (ioctl(0, TIOCGWINSZ, &sh->window.win) != -1)
	{
		ft_get_col_li();
		ft_clean_prompt();
		sh->prompt->first_alt_top = 0;
		sh->window.win_count = 1;
		ft_list_show(sh->prompt->l_char);
	}
}
