/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser .c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

t_cmd	*ft_parse_cmd(char *str)
{
	char 				*begin_cmd;
	char				*second_cmd;
	int 				i;
	int					j;

	i = 0;
	j = ft_strlen(str);
	second_cmd = ft_strnew(1);
	begin_cmd = ft_cut_withspace(str);
	while (i < j && str[i] != '|')
		i++;
	if ((ft_strsub(str, (i + 1), ((i - j) * - 1))) != NULL)
		second_cmd = ft_right_body(ft_strsub(str, (i + 1), ((i - j) * - 1)));
	if (ft_strchr(str, '|'))
		return (ft_build_pipe(begin_cmd, second_cmd));
	/*else if (*str == ';')
		return (ft_create_comma(begin_cmd, second_cmd));
	else if (*str == '<')
		return (ft_create_hook_right(begin_cmd, second_cmd));
	else if (*str == '>')
		return (ft_create_hook_left(begin_cmd, second_cmd));*/
	else
		return (ft_build_exec(begin_cmd));
}

void	ft_main_parser(void)
{	
	t_sh *sh;
	t_cmd *cmd;
	static	int 	i = 0;
	char 	**split;

	sh = ft_sh();
	split = ft_strsplit(sh->prompt->complet_prompt, ';');
	cmd = ft_parse_cmd(split[i]);
	ft_exec_cmd(cmd);
	i++;
}