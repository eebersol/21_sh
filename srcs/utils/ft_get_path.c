/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:36:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 19:36:30 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

char	*ft_get_path(t_list *list, char *b)
{
	char	**env_paths;
	char	*path;
	int		i;

	i = 0;
	env_paths = ft_strsplit(ft_env_get(list, "PATH"), ':');
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		path = ft_freejoin(path, b);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
