#include <stdio.h>

int		main(int argc, char *argv[])
{
	int	i;
	int j;
	int char_count;

	if (argc < 3 || argv[1][1] != '\0')
	{
		printf("Usage: name char words");
		return (1);
	}
	i = 2;
	char_count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == argv[1][0])
			{
				char_count++;
			}
			j++;
		}
		i++;
	}
	printf("%c: %d times\n", argv[1][0], char_count);
	return (0);
}
