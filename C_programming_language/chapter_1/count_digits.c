#include <stdio.h>

#define MAX 500

int		main(void)
{
	char	str[MAX];
	int		digits[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		digits[i] = 0;
		i++;
	}
	fgets(str, MAX, stdin);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digits[str[i] - '0']++;
		}
		i++;
	}
	printf("digits: ");
	i = 0;
	while (i < 10)
	{
		printf("%d->%d, ", i, digits[i]);
		i++;
	}
	return (0);
}
