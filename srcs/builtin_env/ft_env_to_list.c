/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:56:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:56:16 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_env_to_list(t_list **list, char **environ)
{
	t_env	env;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (environ[i])
	{
		j = ft_cut_title(environ[i]);
		env.var = ft_strnew(j + 1);
		ft_strncpy(env.var, environ[i], j);
		env.var[j] = 0;
		env.value = ft_strsub(environ[i], j + 1,
			ft_strlen(ft_strchr(environ[i], '=')));
		ft_lstadd(list, ft_lstnew(&env, sizeof(t_env)));
		i++;
	}
}