#include <stdio.h>

int ft_printf(char *str, ...);

int main(void)
{
printf("\n\nTEST %%x\n\n");
	unsigned int un = (unsigned int)4294967295 + 1;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST %%20x___\n");
	printf("No original - %d\n", ft_printf("|%20x|\n", un));
	printf("Original - %d\n", printf("|%20x|\n", un));

	printf("\n___TEST %%2x___\n");
	printf("No original - %d\n", ft_printf("|%2x|\n", un));
	printf("Original - %d\n", printf("|%2x|\n", un));

	printf("\n___TEST %%.2x___\n");
	printf("No original - %d\n", ft_printf("|%.2x|\n", un));
	printf("Original - %d\n", printf("|%.2x|\n", un));

	printf("\n___TEST %%.20x___\n");
	printf("No original - %d\n", ft_printf("|%.20x|\n", un));
	printf("Original - %d\n", printf("|%.20x|\n", un));

	printf("\n___TEST %%2.20x___\n");
	printf("No original - %d\n", ft_printf("|%2.20x|\n", un));
	printf("Original - %d\n", printf("|%2.20x|\n", un));

	printf("\n___TEST %%22.20x___\n");
	printf("No original - %d\n", ft_printf("|%22.20x|\n", un));
	printf("Original - %d\n", printf("|%22.20x|\n", un));

	printf("\n___TEST %%12.20x___\n");
	printf("No original - %d\n", ft_printf("|%12.20x|\n", un));
	printf("Original - %d\n", printf("|%12.20x|\n", un));

	printf("\n___TEST %%12.x___\n");
	printf("No original - %d\n", ft_printf("|%12.x|\n", un));
	printf("Original - %d\n", printf("|%12.x|\n", un));

	printf("\n___TEST %%.x___\n");
	printf("No original - %d\n", ft_printf("|%.x|\n", un));
	printf("Original - %d\n", printf("|%.x|\n", un));

	printf("\n___TEST %%20.x___\n");
	printf("No original - %d\n", ft_printf("|%20.x|\n", un));
	printf("Original - %d\n", printf("|%20.x|\n", un));

	printf("\n___TEST %%2.x___\n");
	printf("No original - %d\n", ft_printf("|%2.x|\n", un));
	printf("Original - %d\n", printf("|%2.x|\n", un));

	return (0);
	
}
