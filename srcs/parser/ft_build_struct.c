/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

t_cmd	*ft_build_pipe(char *left, char *right)
{
	t_pipe *pipe;

	pipe = (t_pipe*)malloc(sizeof(t_pipe));
	pipe->type = PIPE;
	pipe->left = ft_parse_cmd(left);
	pipe->right = ft_parse_cmd(right);
	return ((t_cmd*)pipe);
}

t_cmd	*ft_build_exec(char *str)
{
	t_exec *exec;
	char **cmd;

	exec = (t_exec*)malloc(sizeof(t_exec));
	exec->type = EXEC;
	cmd = ft_word_to_tab(str);
	exec->cmd = cmd[0];
	exec->opt = cmd;
	return ((t_cmd*)exec);
}