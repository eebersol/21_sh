/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:12:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 16:12:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_delete_char(void)
{
	t_sh *sh;
	t_prompt *prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	ft_lstdel_at(&prompt->l_char, prompt->index - 1, &ft_free_node);
	ft_arrow_left();
	tputs(tgoto((tgetstr("dc", NULL)), 0, 0), 0, tputs_putchar);
}
