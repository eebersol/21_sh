/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_move_word_left(t_prompt *prompt)
{
	if (prompt->first_move_word == 0)
	{
		prompt->complet_prompt = ft_list_to_string();
		prompt->first_move_word = 1;
		ft_arrow_right();
	}
	else if (prompt->complet_prompt[prompt->x - 1] == ' ')
		ft_arrow_left();
	while (prompt->complet_prompt[prompt->x - 1] != ' ' && prompt->x > 0)
		ft_arrow_left();
}

void	ft_move_word_right(t_prompt *prompt)
{
	if (prompt->first_move_word == 0)
	{
		prompt->complet_prompt = ft_list_to_string();
		prompt->first_move_word = 1;
		prompt->x += 2;
	}
	else if (prompt->complet_prompt[prompt->x + 1] == ' ')
		ft_arrow_right();
	while (prompt->complet_prompt[prompt->x] != ' ' &&
		prompt->x >= 0 && prompt->x < ft_lstlen(prompt->l_char))
		ft_arrow_right();
	if (prompt->complet_prompt[prompt->x] == ' ')
		ft_arrow_right();
}

void	ft_move_word(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (SHIFT_L)
		ft_move_word_left(prompt);
	else if (SHIFT_R)
		ft_move_word_right(prompt);
}
