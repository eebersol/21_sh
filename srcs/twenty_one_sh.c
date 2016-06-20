/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twnty_one_sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void	ft_show_banner(t_sh *sh)
{
	int		fd;
	char	*line;

	(void)sh;
	fd = open(".banner", O_RDWR);
	while (get_next_line(fd, &line))
		ft_putendl(line);
	close(fd);
}

t_sh		*ft_sh(void)
{
	static t_sh		sh;

	return (&sh);
}

int			shell(t_sh *sh)
{
	t_prompt	*prompt;

	ft_term_init(sh);
	ft_init_winsize();
	ft_check_signal();
	ft_display_prompt(sh->env);
	while (42)
	{
		ft_init_prompt();
		ft_check_signal();
		sh = ft_sh();
		prompt = sh->prompt;
		ft_get_col_li();
		ft_read_prompt();
		if (prompt->complet_prompt)
		{
			ft_main_parser();
		}
		ft_display_prompt(sh->env);
	}
}

int			main(int ac, char **av, char **environ)
{
	t_sh	*sh;

	(void)av;
	sh = ft_sh();
	if (ac > 1)
		ft_error_ac();
	else
		ft_launch_env(sh, environ);
	ft_show_banner(sh);
	return (shell(sh));
}
