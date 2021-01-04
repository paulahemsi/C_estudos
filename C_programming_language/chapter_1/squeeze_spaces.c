#include <stdio.h>

#define MAX 500

int		main(void)
{
	char	buff[MAX];
	char	new_str[MAX];
	int		i;
	int		j;

	i = 0;
	j = 0;
	fgets(buff, MAX, stdin);
	while (i < MAX)
	{
		if (buff[i] != ' ')
		{
			new_str[j] = buff[i];
			i++;
		}
		else
		{
			new_str[j] = buff[i];
			while (buff[i] == ' ')
			{
				i++;
			}
		}
		j++;
	}
	printf("%s", new_str);
	return (0);
}
