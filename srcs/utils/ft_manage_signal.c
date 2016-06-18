/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 20:22:10 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/17 20:22:12 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	ft_signal_exit(int sig)
{
	t_sh *sh;

	sh = ft_sh();
	ft_reset_prompt();
	ft_term_reset(sh);
	(void)sig;
	exit(0);
	return ;
}

void	ft_check_signal(void)
{
	ft_signal_handler(0);
	signal(SIGQUIT, ft_signal_handler);
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGINT, ft_signal_handler);
}
