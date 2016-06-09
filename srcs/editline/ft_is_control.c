/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_is_control(char *b)
{
	t_sh		*sh;
	t_prompt	*prompt;

	sh = ft_sh();
	prompt = sh->prompt;
	if (ALT_UP)
		ft_alt_up();
	else if (ALT_BOT)
		ft_alt_down();
	else if (S_C || S_V || S_X)
		ft_copy_paste_cut(b);
	else if (S_L || S_R)
		ft_move_word(b);
	else if (HOME)
		ft_go_home();
	else if (END)
		ft_go_end();
	else if (IS_ARROW)
		ft_move_cursor(b);
	else if (CNTRL_D)
		ft_cntrl_d();
	else if (DELETE)
		ft_delete_char();
}
