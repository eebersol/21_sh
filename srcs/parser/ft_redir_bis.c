/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		ft_exec_redirection_bis(t_cmd *cmd)
{
	t_redirection		*rcmd;
	int					new_fd;

	rcmd = (t_redirection*)cmd;
	new_fd = rcmd->mode;
	dup2(new_fd, rcmd->fd);
	ft_exec_cmd(rcmd->cmd);
}
