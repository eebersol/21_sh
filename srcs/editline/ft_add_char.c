/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:12:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 16:12:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_add_char(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;
	t_list		*new_char;

	sh = ft_sh();
	prompt = sh->prompt;
	prompt->index = prompt->x;
	new_char = ft_lstnew(b, (sizeof(char*) * ft_strlen(b)));
	ft_lstadd_at(&prompt->l_char, new_char, prompt->index);
}
