#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	char	c;

	if (argc > 1)
	{
		i = argc - 1;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				c = argv[i][j];
				write(1, &c, 1);
				j++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
}
