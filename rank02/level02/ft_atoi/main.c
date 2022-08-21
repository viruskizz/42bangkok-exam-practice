#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main()
{
	printf("Expect: %d\n", atoi("10"));
	printf("Result: %d\n", ft_atoi("10"));
	printf("Expect: %d\n", atoi("-10"));
	printf("Result: %d\n", ft_atoi("-10"));
	printf("Expect: %d\n", atoi("+10"));
	printf("Result: %d\n", ft_atoi("+10"));
	printf("Expect: %d\n", atoi("    10"));
	printf("Result: %d\n", ft_atoi("    10"));
	printf("Expect: %d\n", atoi("\t\n\v\f\r10"));
	printf("Result: %d\n", ft_atoi("\t\n\v\f\r10"));
	return (0);
}
