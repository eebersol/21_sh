/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:33:50 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/14 18:33:51 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_exit(char **cmd, t_list **list)
{
	int i;

	i = 0;
	if ((ft_error_exit(cmd)) == 0)
	{
		i = (cmd && cmd[1] ? ft_atoi(cmd[1]) : 0);
		ft_tab_free(cmd);
		ft_env_del(list);
		exit(i);
	}
	return (0);
}
