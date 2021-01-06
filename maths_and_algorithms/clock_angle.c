#include <unistd.h>
#include <stdio.h>

//! tá bugado com minutos quebrados (%5 != 0)

int	is_numeric(char *str);
int	wrong_format(int hour, int minute);
int	calc_angle(int hour, int minute);

int	main(int argc, char *argv[])
{
	int hour;
	int minute;

	if (argc != 2 || !is_numeric(argv[1]))
	{
		write(1, "Usage: name hh:mm\n", 19);
		return (1);
	}
	hour = ((argv[1][0] - '0') * 10) + (argv[1][1] - '0');
	minute = ((argv[1][3] - '0') * 10) + (argv[1][4] - '0');
	if (wrong_format(hour, minute))
	{
		write(1, "Usage: name hh:mm\n", 19);
		return (1);
	}
	if (hour > 12)
		hour -= 12;
	printf("%d\n", calc_angle(hour, minute));
}

int	is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (i != 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int	wrong_format(int hour, int minute)
{
	if (hour > 24 || minute > 60)
		return (1);
	return (0);
}

int	calc_angle(int hour, int minute)
{
	int angle;
	int unity;

	unity = minute %5;
	minute /= 5;
	angle = (hour - minute) * 30;
	if (angle < 0)
		angle *= -1;
	if (unity != 0)
		angle += (unity * 6); //! o problema está aqui
	if (angle > 180)
		angle = 360 - angle;
	return (angle);
}
