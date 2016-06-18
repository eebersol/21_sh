/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_error_ac(void)
{
	ft_putendl_fd("Shell can't execute command.", 2);
	exit(0);
}

void	ft_error_not_found(char *varname)
{
	t_sh *sh;

	sh = ft_sh();
	if (sh->prompt->error_quote == 1)
		return ;
	ft_putstr_fd(varname, 2);
	ft_putendl_fd(": command not found", 2);
}

void	ft_error_parser(void)
{
	ft_putendl_fd("21sh : parse error near '\\n'", 2);
}

int		ft_error_bonus(char **cmd)
{
	t_sh	*sh;

	sh = ft_sh();
	if (ft_tab_len(cmd) > 1)
	{
		ft_putendl_fd("Seek_history need oly one numeric argument", 2);
		return (1);
	}
	else if (!cmd[0][1] || ft_isdigit(cmd[0][1]) == 0)
	{
		ft_putendl_fd("Seek_history need numeric argument", 2);
		return (1);
	}
	return (0);
}
