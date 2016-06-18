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

#include <shell.h>

static void			ft_signal_resize(int sig)
{
	(void)(sig);
	ft_resize_window();
}

static void			ft_signal_quit(int sig)
{
	(void)sig;
	return ;
}

static void			ft_signal_background(int sig)
{
	char	cp[2];

	cp[0] = ft_sh()->term.c_cc[VSUSP];
	cp[1] = '\0';
	(void)sig;
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	ft_reset_prompt();
	signal(SIGCONT, ft_signal_handler);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void			ft_signal_foreground(int sig)
{
	t_sh *sh;

	sh = ft_sh();
	signal(SIGTSTP, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	ft_term_init(sh);
	shell(sh);
	(void)sig;
}

void				ft_signal_handler(int sig)
{
	signal(SIGWINCH, ft_signal_resize);
	if (sig == SIGINT)
		ft_signal_quit(sig);
	else if (sig == SIGQUIT)
		ft_signal_exit(sig);
	if (sig == SIGTSTP)
		ft_signal_background(sig);
	else if (sig == SIGCONT)
		ft_signal_foreground(sig);
	return ;
}
