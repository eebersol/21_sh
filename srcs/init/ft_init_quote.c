/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

t_quote	ft_init_quote(void)
{
	t_quote quote;

	quote.parenth_1 = 0;
	quote.parenth_2 = 0;
	quote.double_quote = 0;
	quote.simple_quote = 0;
	quote.black_quote = 0;
	quote.hook_1 = 0;
	quote.hook_2 = 0;
	quote.accolade_1 = 0;
	quote.accolade_2 = 0;
	return (quote);
}