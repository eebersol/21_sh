/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		ft_check_double_quote(t_quote quote, t_prompt *prompt)
{
	prompt->quote_value += quote.double_quote;
	if (prompt->quote_value % 2 != 0)
	{
		ft_putchar('\n');
		ft_putstr("dquote>");
		ft_lstdel(&prompt->l_char, &ft_free_node);
		return (1);
	}
	return (0);
}

int		ft_check_simple_quote(t_quote quote, t_prompt *prompt)
{
	prompt->quote_value += quote.simple_quote;
	if (prompt->quote_value % 2 != 0)
	{
		ft_putchar('\n');
		ft_putstr("quote>");
		ft_lstdel(&prompt->l_char, &ft_free_node);
		return (1);
	}
	return (0);
}

int		ft_check_black_quote(t_quote quote, t_prompt *prompt)
{
	prompt->quote_value += quote.black_quote;
	if (prompt->quote_value % 2 != 0)
	{
		ft_putchar('\n');
		ft_putstr("bquote>");
		ft_lstdel(&prompt->l_char, &ft_free_node);
		return (1);
	}
	return (0);
}

int		ft_check_parenth_quote(t_quote quote, t_prompt *prompt)
{
	prompt->quote_value_parenth += quote.parenth_1;
	prompt->quote_value_parenth -= quote.parenth_2;
	if (prompt->quote_value_parenth != 0)
	{
		if (prompt->complet_prompt[0] == ')')
		{
			ft_putendl_fd("\n21sh : parse error near \')\'", 2);
			prompt->error_quote = 1;
			return (0);
		}
		ft_putchar('\n');
		ft_putstr(" >");
		ft_lstdel(&prompt->l_char, &ft_free_node);
		return (1);
	}
	prompt->complet_prompt = ft_cut_parenth(prompt->complet_prompt);
	return (0);
}

char	*ft_cut_parenth(char *str)
{
	size_t	k;
	size_t	j;
	char	*new_str;

	new_str = ft_strnew(ft_strlen(str));
	j = 0;
	k = 0;
	while (j < ft_strlen(str))
	{
		if (str[j] != '(' && str[j] != ')' && str[j] != '{' && str[j] != '}')
		{
			new_str[k] = str[j];
			k++;
		}
		j++;
	}
	return (new_str);
}
