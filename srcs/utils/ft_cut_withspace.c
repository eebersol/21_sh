/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_withspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int		ft_count_file_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '|' && str[i] != '<' && str[i] != '>')
		i++;
	return (i);
}

char			*ft_cut_withspace(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '|' && str[i] != '<' && str[i] != '>')
		i++;
	new_str = ft_strsub(str, 0, i);
	new_str = ft_strtrim(new_str);
	return (new_str);
}

char			*ft_cut_begin(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	new_str = ft_strsub(str, 0, i);
	new_str = ft_strtrim(new_str);
	return (new_str);
}

char			*ft_cut_secondcmd(char *str, char c, int jump)
{
	char	*new_str;
	char	*len_name;
	int		i;
	int		j;

	i = 0;
	while (str[i] != c)
		i++;
	i += jump;
	len_name = ft_strsub(str, 0, i);
	new_str = ft_strsub(str, i, (ft_strlen(str) - i));
	j = ft_count_file_len(new_str);
	new_str = ft_strsub(str, i, j);
	new_str = ft_strtrim(new_str);
	return (new_str);
}

char			*ft_cut_second_cmd_pipe(char *str)
{
	int		i;
	char	*second_cmd;

	i = 0;
	while (str[i] != '|')
		i++;
	i += 1;
	second_cmd = ft_strsub(str, i, ft_strlen(str) - i);
	return (second_cmd);
}
