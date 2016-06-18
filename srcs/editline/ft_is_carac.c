/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_carac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:33:50 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/14 18:33:51 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_is_carac(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (TAB)
		b = ft_strdup(" ");
	if (prompt->x == prompt->lenght)
	{
		ft_add_char(b);
		prompt->x++;
		prompt->index++;
		ft_putchar(b[0]);
		prompt->lenght++;
	}
	else
	{
		tputs(tgoto((tgetstr("sc", NULL)), 0, 0), 0, tputs_putchar);
		ft_add_char(b);
		ft_list_shower(prompt->l_char, prompt);
		tputs(tgoto((tgetstr("rc", NULL)), 0, 0), 0, tputs_putchar);
		ft_arrow_right();
		prompt->lenght++;
		prompt->index = prompt->x;
	}
}
