/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

char	*ft_read_prompt(void)
{
	t_sh *sh;
	t_prompt *prompt;
	char b[7];

	sh = ft_sh();
	prompt = sh->prompt;
	ft_bzero(b, 7);
	while (read (0, b, 7))
	{
		//printf("b[0] = %d b[1] = %d b[2] = %d b[3] = %d b[4] = %d b[5] = %d\n", b[0], b[1], b[2], b[3], b[4], b[5]);
		prompt->lenght = ft_lstlen(prompt->l_char);
		if (SHIFT_L || SHIFT_R)
			ft_move_word(b);
		else if (SHIFT_C || SHIFT_V || SHIFT_X)
			ft_copy_paste_cut(b);
		else if (IS_ARROW || CNTRL || DELETE || HOME || END || ALT_UP || ALT_BOT)
			ft_is_control(b);
		else if (ENTER)
		{
			ft_history();
			if (ft_check_quote() == 1)
			{
				ft_lstdel(&prompt->l_char, &ft_free_node);
				ft_bzero(b, 7);
				prompt->x = 0;
				prompt->index = 0;
				ft_read_prompt();
			}
			ft_putchar('\n');
			return (0);
		}
		else
			ft_is_carac(b);
		ft_bzero(b, 7);
	}
	return (0);
}
