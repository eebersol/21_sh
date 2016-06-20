/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_to_lchar.c                              :+:      :+:    :+:   */
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
	int			i;
	int			j;

	sh = ft_sh();
	prompt = sh->prompt;
	i = 0;
	j = 0;
	prompt->index = 0;
	while ((size_t)i < ft_strlen(str))
	{
		dst = ft_strnew(1);
		dst[j] = str[i];
		ft_add_char(dst);
		prompt->index++;
		ft_strdel(&dst);
		i++;
	}
}
