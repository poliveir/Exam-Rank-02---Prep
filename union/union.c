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
	int j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used_char[i++] = 0;
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (used_char[(int)argv[i][j]] == FALSE)
				{
					used_char[(int)argv[i][j]] = TRUE;
					ft_putchar(argv[i][j]);
				}
				j++;
			}
			i++;
		}	
	}
	ft_putchar('\n');
	return(0);	
}
