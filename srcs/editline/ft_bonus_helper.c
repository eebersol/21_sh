/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:55:56 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/18 18:55:58 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	void	ft_aff_helper_builtin(void)
{
	ft_putendl_fd("\n1. cd [opt] [path]", 0);
	ft_putendl_fd("2. env [-i] [var=value, ....] [cmd]", 0);
	ft_putendl_fd("3. setenv [var] [value]", 0);
	ft_putendl_fd("4. unsetenv [var]", 0);
	ft_putendl_fd("5. exit [value]\n", 0);
}

static	void	ft_aff_helper_editline(void)
{
	ft_putendl_fd("\n 1. shift + ->/<- : move word by word.", 0);
	ft_putendl_fd(" 2. alt + UP/DOWN : up/down one line.", 0);
	ft_putendl_fd(" 3. alt + c : begin cpy mode press again to stop.", 0);
	ft_putendl_fd(" 4. alt + x : begin cut mode, press again to stop.", 0);
	ft_putendl_fd(" 5. alt + v : past the copy sentence.", 0);
	ft_putendl_fd(" 6. HOME/END : move to the begin or end of the prompt.", 0);
	ft_putendl_fd(" 7. cntrl + z : pass 21sh on foreground.", 0);
	ft_putendl_fd(" 8. cntrl + d : exit 21sh.", 0);
	ft_putendl_fd(" 9. cntrl + h : show complet historic.", 0);
	ft_putendl_fd("10. ! + [num] : move at [num] in the historic", 0);
	ft_putendl_fd("11. DOWN/UP : move to the historic.\n", 0);
}

static	void	ft_aff_helper_redirection(void)
{
	ft_putendl_fd("\n1. [|]", 0);
	ft_putendl_fd("2. [>]    - [>>]", 0);
	ft_putendl_fd("3. [<]    - [<<]", 0);
	ft_putendl_fd("4. [2>]   - [2>>]", 0);
	ft_putendl_fd("5. [1>&2] - [2>&1]", 0);
	ft_putendl_fd("6. [1>&-] - [2>&-]\n", 0);
}

void			ft_helper(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("\nhelp [...], please choose categorie : ", 2);
		ft_putendl_fd("| builtin - editline - redirection |\n", 2);
	}
	else if (ft_strcmp(str, "builtin") == 0)
		ft_aff_helper_builtin();
	else if (ft_strcmp(str, "editline") == 0)
		ft_aff_helper_editline();
	else if (ft_strcmp(str, "redirection") == 0)
		ft_aff_helper_redirection();
	else
	{
		ft_putstr_fd("\ncategorie not found : please choose categorie : ", 2);
		ft_putendl_fd("| builtin - editline - redirection |\n", 2);
	}
}
