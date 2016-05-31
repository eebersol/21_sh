/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:32:34 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/25 16:32:35 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_error_env(char **cmd)
{
	if ((ft_strcmp(cmd[0], "env") == 0) && !cmd[1])
		return (0);
	else if (cmd[1] && cmd[1][0] != '-')
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(" : No such file or directory", 2);
		return (-1);
	}
	else if (cmd[1] && ((ft_strcmp(cmd[1], "-v") != 0)
		|| (ft_strcmp(cmd[1], "-P") != 0) || (ft_strcmp(cmd[1], "-S") != 0)
		|| (ft_strcmp(cmd[1], "-u") != 0) || (ft_strcmp(cmd[1], "--") != 0)
		|| (ft_strcmp(cmd[1], "--") != 0)))
	{
		ft_putstr_fd("env: illegal option -- ", 2);
		ft_putchar_fd((ft_seek_wrong_opt(cmd[1])), 2);
		ft_putchar('\n');
		ft_putstr_fd("usage: env [-iv] [-P utilpath][-S string] [-u name]", 2);
		ft_putendl_fd("[-S string] [-u name]", 2);
		ft_putstr_fd("           ", 2);
		ft_putendl_fd("[name=value ...] [utility [argument ...]]", 2);
		return (-1);
	}
	return (0);
}
