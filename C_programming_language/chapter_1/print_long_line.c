#include <stdio.h>

#define MAXLINE 1000

int		ft_getline(char line[], int maxline);
void	copy(char to[], char from[]);

int		main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = ft_getline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
	{
		printf("\nlongest line: %s", longest);
	}
	return (0);
}

int		ft_getline(char line[], int maxline)
{
	int c;
	int i;

	i = 0;
	while ((i < (maxline - 1)) && (c = getchar()) != EOF && c != '\n')
	{
		line[i] = c;
		i++;
	}
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return (i);
}

void	copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		i++;
	}
}

//* obs: ^D in stdin works as EOF//
