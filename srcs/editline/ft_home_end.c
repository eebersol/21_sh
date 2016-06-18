/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_go_home(void)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	while (prompt->x > 0)
		ft_arrow_left();
}

void	ft_go_end(void)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	while (prompt->x < ft_lstlen(prompt->l_char))
		ft_arrow_right();
}
