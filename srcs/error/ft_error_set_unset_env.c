/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_set_unset_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:38:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/25 16:38:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		ft_error_set_unset_env(char **cmd, char *name)
{
	if ((ft_tab_len(cmd)) <= 1)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": You must provide a variable", 2);
		return (-1);
	}
	else if ((ft_tab_len(cmd)) > 3 && ft_strcmp(name, "setenv") == 0)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": Two many arguments", 2);
		return (-1);
	}
	else if ((ft_isalphanumeric(cmd[1]) == 1)
		&& ((ft_strcmp(name, "setenv")) == 0))
	{
		ft_putstr_fd("setenv: Variable name must", 2);
		ft_putendl_fd(" contain alphanumeric characters.", 2);
		return (-1);
	}
	printf("ls\n");
	return (0);
}
