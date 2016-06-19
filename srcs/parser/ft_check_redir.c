/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		ft_chkrdir(char *s1)
{
	size_t	j;

	j = 1;
	while (j < ft_strlen(s1))
	{
		if (s1[j - 1] != '2' && s1[j] == '>' && s1[j + 1] == '>')
			return (1);
		else if (s1[j] == '>' && s1[j - 1] != '<' && s1[j - 1] != '>'
			&& s1[j - 1] != '1' && s1[j - 1] != '2' && s1[j + 1] != '<'
			&& s1[j + 1] != '>' && s1[j + 1] != '1' && s1[j + 1] != '2')
			return (2);
		else if (s1[j] == '<' && s1[j + 1] == '<')
			return (3);
		else if (s1[j] == '<' && s1[j - 1] != '<' && s1[j - 1] != '>'
			&& s1[j - 1] != '1' && s1[j - 1] != '2' && s1[j + 1] != '<'
			&& s1[j + 1] != '>' && s1[j + 1] != '1' && s1[j + 1] != '2')
			return (4);
		j++;
	}
	return (0);
}

int		ft_chkrdir_err(char *s1)
{
	size_t	j;

	j = 1;
	while (j < ft_strlen(s1))
	{
		if (s1[j - 1] == '2' && s1[j] == '>' && s1[j + 1] != '>'
			&& s1[j + 1] != '&')
			return (1);
		else if (s1[j - 1] == '2' && s1[j] == '>' && s1[j + 1] == '>')
			return (2);
		else if (s1[j] == '1' && s1[j + 1] == '>' && s1[j + 2] == '&'
			&& s1[j + 3] == '2')
			return (3);
		else if (s1[j] == '2' && s1[j + 1] == '>' && s1[j + 2] == '&'
			&& s1[j + 3] == '1')
			return (4);
		j++;
	}
	return (0);
}

int		ft_chkrdir_close(char *s1)
{
	size_t	j;

	j = 1;
	while (j < ft_strlen(s1))
	{
		if (s1[j] == '2' && s1[j + 1] == '>' && s1[j + 2] == '&'
			&& s1[j + 3] == '-')
			return (1);
		else if (s1[j] == '1' && s1[j + 1] == '>' && s1[j + 2] == '&'
			&& s1[j + 3] == '-')
			return (2);
		j++;
	}
	return (0);
}
