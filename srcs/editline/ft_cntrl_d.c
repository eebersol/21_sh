/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntrl_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_cntrl_d(void)
{
	t_sh *sh;
	t_prompt *prompt;
	int 	i;

	sh = ft_sh();
	prompt = sh->prompt;
	i = prompt->x;
	prompt->index_d = ft_lstlen(prompt->l_char) - 1;
	prompt->complet_prompt = ft_list_to_string();
	if (prompt->index_d > prompt->x)
	{
		prompt->complet_prompt = ft_strsub(prompt->complet_prompt, 0, prompt->index_d);
		tputs(tgoto((tgetstr("sc", NULL)), 0, 0), 0, tputs_putchar);
		ft_clean_prompt();
		ft_history_to_lchar(prompt->complet_prompt);
		ft_list_show(prompt->l_char);
		prompt->x = i;
		prompt->index = i;
		tputs(tgoto((tgetstr("rc", NULL)), 0, 0), 0, tputs_putchar);
	}
}