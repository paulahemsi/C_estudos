#include <stdio.h>

int			is_space(char c);
int			is_sign(char c);
int			is_number(char c);
float		ft_atoi(const char *str);
int			ft_str_is_number(char *str);

//?mexer na atoi para aceitar float?//

int			main(int argc, char *argv[])
{
	if (argc != 2 || !ft_str_is_number(argv[1]))
	{
		printf("Usage: name celsius\n");
		return (1);
	}
	printf("Fahrenheit: %.1f\n", (ft_atoi(argv[1]) * 1.8) + 32);
}

float			ft_atoi(const char *str)
{
    int i;
    float num;
    float neg;

    i = 0;
    num = 0.0;
    neg = 1.0;
    while (is_space(str[i]))
    {
        i++;
    }
    if (is_sign(str[i]))
    {
        if (str[i] == '-')
        {
            neg *= -1;
        }
        i++;
    }
    while (is_number(str[i]))
    {
        num *= 10;
        num += (str[i] - '0');
        i++;
    }
    return (num * neg);
}

int			is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int			is_sign(char c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	return (0);
}

int			is_number(char c)
{
	if (c  >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int			ft_str_is_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
	{
		i++;
		if (str[1] == '\0')
		{
			return (0);
		}
	}
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
