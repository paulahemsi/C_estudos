#include <unistd.h>

#define NUM_INIT -1
#define INDEX_INIT 0

void	ft_print_combn(int n);
void	recursive_combn(int num, int numbers[], int index, int n);
void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][1] != '\0')
	{
		write(1, "Usage: name number(1 - 9)\n", 27);
		return (1);
	}
	if ((argv[1][0] - '0') <= 0 || (argv[1][0] - '0') > '9')
	{
		write(1, "Usage: name number(1 - 9)\n", 27);
		return (1);
	}
	ft_print_combn(argv[1][0] - '0');
	return (0);
}

void	ft_print_combn(int n)
{
	int	numbers[n];

	recursive_combn(NUM_INIT, numbers, INDEX_INIT, n);
}

void	recursive_combn(int num, int numbers[], int index, int n)
{
	int	index_count;

	if (index == n)
	{
		index_count = 0;
		while (index_count <= index - 1)
		{
			ft_putchar(numbers[index_count] + '0');
			index_count++;
		}
		ft_putchar(' ');
		return;
	}
	num += 1;
	while (num <= 9)
	{
		numbers[index] = num;
		recursive_combn(num, numbers, (index + 1), n);
		num++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
