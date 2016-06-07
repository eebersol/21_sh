/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 20:22:10 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/17 20:22:12 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static void		ft_signal_quit(int sig)
{
	(void)sig;
	return ;
}

void			ft_check_signal(void)
{
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGTSTP, ft_signal_quit);
	signal(SIGINT, ft_signal_quit);
}
