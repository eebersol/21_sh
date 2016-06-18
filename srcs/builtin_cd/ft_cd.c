/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:58:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/12 15:58:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_cd(t_list *list, char **cmd)
{
	t_env	*env;
	int		i;
	int		ret;
	char	old_pwd[2048];
	char	new_pwd[2048];

	if (ft_error_cd(cmd) == 0)
	{
		env = list->content;
		i = 0;
		ret = 0;
		getcwd(old_pwd, 2048);
		if (cmd[i + 1] == NULL || (ft_strcmp(cmd[i + 1], "~") == 0)
			|| ((ft_strcmp(cmd[i + 1], " ")) == 0))
			chdir(ft_env_get(list, "HOME"));
		else if ((ft_strcmp(cmd[i + 1], "..")) == 0)
			chdir("..");
		else if ((ft_strcmp(cmd[i + 1], "-")) == 0)
			chdir(ft_env_get(list, "OLDPWD"));
		else
			chdir(cmd[i + 1]);
		getcwd(new_pwd, 2048);
		ft_env_set(&list, "OLDPWD", ft_strdup(old_pwd));
		ft_env_set(&list, "PWD", ft_strdup(new_pwd));
	}
}
