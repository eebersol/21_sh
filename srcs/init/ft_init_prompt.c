/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_init_sh(void)
{
	t_sh *sh;

	sh = ft_sh();
}

void	ft_init_prompt(void)
{
	t_sh *sh;
	static int first_time;

	sh = ft_sh();
	if (first_time == 0)
	{
		sh->prompt = (t_prompt*)malloc(sizeof(t_prompt));
		sh->prompt->history = NULL;
		sh->prompt->history_len = 0;
		sh->prompt->index_history = 0;
		sh->prompt->history_len = 0;
	}
	sh->prompt->x = 0;
	sh->prompt->y = 0;
	sh->prompt->index = 0;
	sh->prompt->l_char = NULL;
	sh->prompt->lenght = 0;
	sh->prompt->first_top = 0;
	sh->prompt->first_process = 0;
	sh->prompt->quote_value = 0;
	sh->prompt->quote_value_parenth = 0;
	sh->prompt->index_word = 0;
	sh->prompt->complet_prompt = ft_strnew(1);
	sh->prompt->first_move_word = 0;
	sh->prompt->index_d = 0;
	first_time = 1;
}
