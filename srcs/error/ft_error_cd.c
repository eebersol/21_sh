/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:32:56 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/25 16:32:57 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_error_no_directory(char **cmd)
{
	struct stat my_stat;

	stat(cmd[1], &my_stat);
	ft_putstr_fd("cd: ", 2);
	if ((access(cmd[1], F_OK)) == -1)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (!(S_ISDIR(my_stat.st_mode)))
		ft_putstr_fd("not directory: ", 2);
	else
		ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(cmd[1], 2);
}

int		ft_error_cd(char **cmd)
{
	if ((access(cmd[1], F_OK)) == -1 && !cmd[2] && (ft_strcmp(cmd[1], "~") != 0)
		&& (ft_strcmp(cmd[1], "-") != 0))
		ft_error_no_directory(cmd);
	else if (cmd[0] && cmd[1] && cmd[2] && cmd[3])
		ft_putendl_fd("cd: too many arguments", 2);
	else if ((cmd[1]) && cmd[2])
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(cmd[1], 2);
	}
	else
		return (0);
	return (1);
}
