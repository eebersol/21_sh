/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	void	ft_aff_history(t_sh *sh, int j)
{
	t_list	*cur;

	ft_lstdel(&sh->prompt->l_char, &ft_free_node);
	cur = ft_lstget_at(sh->prompt->history, j);
	ft_history_to_lchar(cur->content);
	ft_list_show(sh->prompt->l_char);
	sh->prompt->x = ft_lstlen(sh->prompt->l_char);
	ft_strdel(&sh->prompt->complet_prompt);
	ft_read_prompt();
	sh->prompt->x = ft_strlen(sh->prompt->complet_prompt);
	ft_lstdel(&sh->prompt->l_char, &ft_free_node);
	ft_history_to_lchar(sh->prompt->complet_prompt);
	ft_main_parser();
}

void			ft_list_history(void)
{
	t_sh	*sh;

	sh = ft_sh();
	ft_putchar('\n');
	ft_list_show_to(sh->prompt->history);
	ft_display_prompt(sh->env);
}

void			ft_seek_to_history(char **cmd)
{
	t_sh	*sh;
	char	*str;
	size_t	i;
	int		j;

	sh = ft_sh();
	str = NULL;
	i = 0;
	j = 0;
	if (ft_error_bonus(cmd) == 1)
		return ;
	tputs(tgoto((tgetstr("up", NULL)), 0, 0), 0, tputs_putchar);
	while (i++ < (4 + ft_strlen(cmd[0])))
		tputs(tgoto((tgetstr("nd", NULL)), 0, 0), 0, tputs_putchar);
	ft_clean_prompt();
	if ((ft_isdigit(cmd[0][1])) == 1)
		str = ft_freejoin(str, &cmd[0][1]);
	j = ft_atoi(str);
	if (j < 0 || j > ft_lstlen(sh->prompt->history))
	{
		ft_putendl_fd("Wrong index history", 2);
		return ;
	}
	else
		ft_aff_history(sh, j);
}
