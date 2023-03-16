#include "unistd.h"

void isend()
void rstr(char *str)
{
	int i = 0;
	int len = 0;

	while (str[len])
		len++;
	while (i < len - 1)
	{
		if (str[i] == '\t' || str[i] == ' ')
			i++;
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			if (str[i + 1] == '\t'|| str[i + 1] == ' ' || str[i + 1] == 0)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
		}
		i++;
	}
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	i = -1;

	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}


int main (int ac, char **av)
{
	int i =0;
	if (ac >= 2)
	{
		while(av[++i])
		{
			rstr(av[i]);
			if (ac > 2)
				write(1, "\n",1);
		}
	}
	else
		write(1, "\n",1);
	return (0);
}