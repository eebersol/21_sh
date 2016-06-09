/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	ft_term_init(t_sh *sh)
{
	char	buff_env[4096];

	if ((sh->term_name = getenv("TERM")) == NULL)
	{
		printf("1\n");
		exit(1);
	}
	if (tgetent(buff_env, sh->term_name) != 1)
	{
		printf("2\n");
		exit(1);
	}
	if (tcgetattr(0, &sh->term) == -1)
	{
		printf("3\n");
		exit(1);
	}
	sh->term.c_lflag &= ~(ICANON);
	sh->term.c_lflag &= ~(ECHO);
	sh->term.c_cc[VMIN] = 1;
	sh->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &sh->term) == -1)
		exit(1);
}

void	ft_term_reset(t_sh *sh)
{
	char	buff_env[4096];

	if ((sh->term_name = getenv("TERM")) == NULL)
		return ;
	if (tgetent(buff_env, sh->term_name) != 1)
		return ;
	if (tcgetattr(0, &sh->term) == -1)
		return ;
	sh->term.c_lflag = (ICANON | ECHO | ISIG);
	if (tcsetattr(0, 0, &sh->term) == -1)
		return ;
}
