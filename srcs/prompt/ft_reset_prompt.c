/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_reset_prompt(void)
{
	t_sh *sh;

	sh = ft_sh();
	sh->term.c_lflag = (ICANON | ECHO | ISIG);
	if (tcsetattr(0, TCSANOW, &sh->term) == -1)
		return (0);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	return (1);
}