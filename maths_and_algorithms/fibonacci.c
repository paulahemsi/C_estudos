#include <unistd.h>

int	ft_fibonacci(int index);
int	ft_str_is_number(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int	ft_atoi(const char *str);
int	is_space(char c);
int	is_sign(char c);
int	is_number(char c);

int		main(int argc, char *argv[])
{
	if (argc != 2 || !ft_str_is_number(argv[1]))
	{
		write(1, "Usage: name index\n", 26);
		return (1);
	}
	ft_putnbr(ft_fibonacci(ft_atoi(argv[1])));
	write(1, "\n", 1);
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

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		number = nb * -1;
		ft_putchar('-');
	}
	else
	{
		number = nb;
	}
	if (number / 10 < 1)
	{
		ft_putchar(number + '0');
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	return ((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2)));
}

int ft_atoi(const char *str)
{
    int i;
    int num;
    int neg;

    i = 0;
    num = 0;
    neg = 1;
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

int		is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int		is_sign(char c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	return (0);
}

int		is_number(char c)
{
	if (c  >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
