#include <unistd.h>

void	rstr_capitalizer(char **str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		while (str[i][j])
		{
			while (str[i][j] ==  ' ' || str[i][j] == '\t')
				j++;
			if ((str[i][j] >= 'a' && str[i][j] <= 'z') || (str[i][j] >= 'A' && str[i][j] <= 'Z'))
				{
					if (str[i][j] <= 'a' && str[i][j] >= 'z') || (str[i][j] <= 'A' && str[i][j] >= 'Z')
				}
		}
	}
}

int main(int ac, char **av)
{

	return (0);
}