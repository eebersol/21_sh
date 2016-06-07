/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_sh->prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>


static void	ft_launch_cmd(t_sh *sh)
{
	ft_lstdel(&sh->prompt->l_char, &ft_free_node);
//	ft_bzero(b, 7);
	sh->prompt->x = 0;
	sh->prompt->index = 0;
	ft_read_prompt();
}

char	*ft_read_prompt(void)
{
	t_sh		*sh;
	char		b[7];

	sh = ft_sh();
	ft_bzero(b, 7);
	while (read(0, b, 7))
	{
		sh->prompt->lenght = ft_lstlen(sh->prompt->l_char);
		if (IS_ARROW || CNTRL || DELETE || HOME || END || ALT_UP
			|| ALT_BOT || S_C || S_V || S_X || S_L || S_R)
			ft_is_control(b);
		else if (ENTER)
		{
			ft_history();
			if (ft_check_quote(sh) == 1)
				ft_launch_cmd(sh);
			ft_putchar('\n');
			return(0);
		}
		else
			ft_is_carac(b);
		ft_bzero(b, 7);
	}
	return (0);
}
