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

void	ft_launch_env(t_sh *sh, char **environ)
{
	ft_env_to_list(&(sh->env), environ);
	ft_env_set(&(sh->env), "SHLVL",
		ft_itoa((ft_atoi(ft_env_get(sh->env, "SHLVL")) + 1)));
}
