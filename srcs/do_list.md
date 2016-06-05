Tester HOME et END










char  *ft_get_opt(char *str)
{
	char 		*b;
	static char *opt;
	char 		*tmp;
	char 		*salut;
	char 		*content;

	content = NULL;
	tmp = NULL;
	b = ft_strnew(1);
	ft_putchar('>');
	while (read (0, b, 1))
	{
		ft_putchar(b[0]);	
		content = ft_strdup(ft_freejoin(content, b));
		if (ENTER)
		{
			content = ft_strtrim(content);
			if (ft_strcmp(content, str) == 0)
			{
				tmp = ft_strdup(opt);
				//opt = NULL;
				return (tmp);
			}
			else
			{
				opt = ft_strdup(ft_freejoin(opt, content));
				opt = ft_strdup(ft_freejoin(opt, " "));
				ft_get_opt(str);
			}
			salut = ft_strdup(opt);
			return (salut);
		}
	}
	return (" ");
}
