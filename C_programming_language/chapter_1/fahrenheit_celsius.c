#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int		main(void)
{
	float fahr;
	float celsius;

	fahr = LOWER;
	printf("\nfahr\tcelsius\n\n");
	while (fahr <= UPPER)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%4.0f  %8.1f\n", fahr, celsius);
		fahr = fahr + STEP;
	}
}
