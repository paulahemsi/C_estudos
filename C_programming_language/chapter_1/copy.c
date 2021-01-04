#include <stdio.h>

#define MAX 256
int		main(void)
{
	char buf[MAX];

	fgets(buf, MAX, stdin);
	printf("%s", buf);
	return (0);

	// while ((c = getchar()) != EOF)
	// {
	// 	putchar(c);
	// }
}
