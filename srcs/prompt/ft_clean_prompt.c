/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_clean_prompt(void)
{
	t_sh *sh;
	t_prompt *prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	prompt->lenght = ft_lstlen(prompt->l_char);
	while (prompt->x < prompt->lenght)
		ft_arrow_right();
	while (prompt->x > 0)
		ft_delete_char();
}

void 	ft_clean_history(char *str)
{
	int i;
	i = ft_strlen(str);
	while(i > 0)
	{
		tputs(tgoto((tgetstr("le", NULL)), 0, 0), 0, tputs_putchar);
		tputs(tgoto((tgetstr("dc", NULL)), 0, 0), 0, tputs_putchar);
		i--;
	}
}
