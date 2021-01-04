#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int		is_space(char c);
char	*replace(char *buf, int new_max);

int		main(void)
{
	char	buf[MAX];
	char	*new_str;
	int		new_max;
	int		i;

	fgets(buf, MAX, stdin);
	new_max = 0;
	i = 0;
	while (i < (MAX - 1))
	{
		if (is_space(buf[i]))
		{
			new_max++;
		}
		i++;
	}
	new_str = replace(buf, (MAX + new_max));
	printf("%s", new_str);
	free(new_str);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

char	*replace(char *buf, int new_max)
{
	int		i;
	int		j;
	char	*new_str = malloc(sizeof(char) * new_max);

	if (new_str == NULL)
	{
		return(new_str);
	}
	i = 0;
	j = 0;
	while (i < (MAX - 1))
	{
		if (buf[i] == ' ')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = '_';
		}
		else if (buf[i] == '\v')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = 'v';
		}
		else if (buf[i] == '\n')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = 'n';
		}
		else if (buf[i] == '\t')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = 't';
		}
		else if (buf[i] == '\r')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = 'r';
		}
		else if (buf[i] == '\f')
		{
			new_str[j] = '\\';
			j++;
			new_str[j] = 'f';
		}
		else
		{
			new_str[j] = buf[i];
		}
		i++;
		j++;
	}
	return (new_str);
}
