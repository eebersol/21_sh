/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 19:17:37 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/14 19:17:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_tab_free(char **tab)
{
	int			i;
	int			len;

	i = 0;
	len = tbl_len(*tab);
	while (i < len)
	{
		free(*tab[i]);
		i++;
	}
	free(*tab);
	return (0);
}
