/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:32:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/25 16:32:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		ft_error_exit(char **cmd)
{
	if (cmd && cmd[1] && cmd[2])
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": unique numeric argument required", 2);
		return (-1);
	}
	else
		return (0);
}
