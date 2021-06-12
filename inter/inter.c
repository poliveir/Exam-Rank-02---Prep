#include <unistd.h>

#define TRUE 1
#define FALSE 0

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int used_char[255];
	int i;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used_char[i++] = 0;
		i = 0;
		while (argv[2][i])
		{
			if (used_char[(int)argv[2][i]] == FALSE)
				used_char[(int)argv[2][i]] = TRUE;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (used_char[(int)argv[1][i]] == TRUE)
			{
				ft_putchar(argv[1][i]);
				used_char[(int)argv[1][i]]++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return(0);
}
