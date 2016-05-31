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

#include <21sh.h>

char	*ft_cut_withspace(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '|')
		i++;
	new_str = ft_strsub(str, 0, i);
	new_str = ft_strtrim(new_str);
	return (new_str);
}

char	*ft_right_body(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	new_str = ft_strdup(str);
	new_str = ft_strtrim(new_str);
	return (new_str);
}