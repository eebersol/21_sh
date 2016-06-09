/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:49:27 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/24 16:49:29 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_display_prompt(t_list *env)
{
	char	*path;
	char	*name;

	name = ft_env_get(env, "LOGNAME");
	path = ft_strjoin("~", (ft_strsub((ft_env_get(env, "PWD")),
		(ft_strlen(ft_env_get(env, "HOME"))),
		(ft_strlen((ft_env_get(env, "PWD"))) -
			(ft_strlen(ft_env_get(env, "HOME")))))));
	ft_putstr(BLUE);
	ft_putstr("☾ ");
	ft_putstr(name);
	ft_putstr(" ☽ ");
	ft_putstr(GREEN);
	ft_putstr("❝ ");
	ft_putstr(path);
	ft_putstr(" ❞");
	ft_putendl(BLUE);
	ft_putstr(" ⇨ ");
	ft_putstr("\033");
	ft_putstr(WHITE);
	ft_putstr(":");
}