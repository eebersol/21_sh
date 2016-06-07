/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

char	*ft_list_to_string(void)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*cur;

	sh = ft_sh();
	prompt = sh->prompt;
	cur = prompt->l_char;
	while (cur)
	{
		prompt->complet_prompt = ft_freejoin(prompt->complet_prompt,
			(char*)cur->content);
		cur = cur->next;
	}
	return (prompt->complet_prompt);
}
