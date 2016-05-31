t_cmd *create_pipe(char *left, char *right)
{
	t_pipe *pipe;

	pipe = malloc(sizeof(t_pipe));
	pipe->type = 1;
	pipe->left = parse_cmd(left);
	pipe->right = parse_cmd(right);

	return ((t_cmd *) pipe);
}

t_cmd *create_exec(char *str)
{
	t_exec *exec;

	exec = malloc(sizeof(t_exec));
	exec->type = 3;
	exec->cmd = str;
	return ((t_cmd *) exec);
}

t_cmd *parse_cmd(char *str)
{
	char *start;

	start = str;

	while (*str && *str = ' ')
		str++;
	if (*str == '|')
		return create_pipe(before_pipe, after_pipe);
	else
		return create_exec(str);
}

void	exec_pipe(t_cmd *left, t_cmd *right)
{
	fork();
	dup();
	exec_cmd(left);
	exec_cmd(right);
}

void	exec_cmd(t_cmd *cmd)
{
	t_pipe *pipe;
	if (cmd->type == 1)
	{
		pipe = (t_pipe *)cmd;
		exec_pipe(cmd);
	}
	if (cmd->type == 3)
	{
		exec = (t_exec *)cmd;
		fork();
		execve(exec->cmd);
	}
}

void	main(void)
{
	t_cmd *cmd;

	cmd = parse_cmd("ls -a | cat -e | wc");
	exec_cmd(cmd);
}