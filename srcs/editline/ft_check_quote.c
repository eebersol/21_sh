/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_check_number_quote(t_sh *sh, t_quote quote)
{
	if (quote.double_quote != 0
		&& ft_check_double_quote(quote, sh->prompt) == 1)
		return (1);
	else if (ft_check_simple_quote(quote, sh->prompt) == 1)
		return (1);
	else if (ft_check_parenth_quote(quote, sh->prompt) == 1)
		return (1);
	else if (ft_check_black_quote(quote, sh->prompt) == 1)
		return (1);
	else
		return (0);
}

int		ft_check_quote(t_sh *sh)
{
	t_list		*cur;
	t_quote		quote;
	char		c;

	cur = sh->prompt->l_char;
	quote = ft_init_quote();
	while (cur)
	{
		c = *((char *)cur->content);
		if (c == '"')
			quote.double_quote++;
		else if (c == '\'')
			quote.simple_quote++;
		else if (c == '`')
			quote.black_quote++;
		else if (c == '(')
			quote.parenth_1++;
		else if (c == ')')
			quote.parenth_2++;
		cur = cur->next;
	}
	if (ft_check_number_quote(sh, quote) == 1)
		return (1);
	return (0);
}
