/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_lchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_history_to_lchar(char *str)
{
	t_sh		*sh;
	t_prompt	*prompt;
	char		*dst;
	size_t		i;
	int			j;

	sh = ft_sh();
	prompt = sh->prompt;
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		dst = ft_strnew(1);
		dst[j] = str[i];
		ft_lstadd(&prompt->l_char,
			ft_lstnew(dst, (sizeof(char*) * ft_strlen(dst))));
		prompt->index++;
		ft_strdel(&dst);
		i++;
	}
	ft_lstrev(&prompt->l_char);
	str[i] = '\0';
}
