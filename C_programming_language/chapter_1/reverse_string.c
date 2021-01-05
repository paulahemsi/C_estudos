#include <unistd.h>

int	calc_len(char argv[]);

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int length;

	if (argc == 1)
	{
		write(1, "Usage: name words\n", 19);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		length = calc_len(argv[i]);
		j = length - 1;
		while (j >= 0)
		{
			write(1, &argv[i][j], 1);
			j--;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	calc_len(char argv[])
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	return (i);
}
