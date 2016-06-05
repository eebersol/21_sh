/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

t_sh	*ft_sh(void)
{
	static t_sh		sh;

	return (&sh);
}

int		shell(t_sh *sh)
{
	t_prompt *prompt;

	ft_putstr("$>");
	ft_init_winsize();
	while (42)
	{
		ft_term_init(sh);
		ft_init_prompt();
		sh = ft_sh();
		prompt = sh->prompt;
		ft_get_col_li();
		ft_read_prompt();
		//ft_lstdel(&prompt->l_char, &ft_free_node);
		if (prompt->complet_prompt)
		{
			ft_();
		//	ft_reset_prompt();
		//	ft_strdel(&prompt->complet_prompt);
		}
		ft_putstr("$>");

	}
	
}

int 	main(int ac, char **av, char **environ)
{
	t_sh *sh;

	sh = ft_sh();
	(void)av;
	if (ac > 1)
		ft_error_ac();
	else
		ft_launch_env(sh, environ);
	return (shell(sh));
}
