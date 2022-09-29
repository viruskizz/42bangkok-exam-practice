#include <stdio.h>

int	ft_printf(const char*, ...);

int main()
{
	int		len;
	char	*str;

	// len = printf("Hello %s\n", str);
	// printf("%d\n", len);
	// len = ft_printf("Hello %s\n", str);
	// printf("%d\n", len);

	// len = printf("Hello %s\n", "Araiva");
	// printf("%d\n", len);
	// len = ft_printf("Hello %s\n", "Araiva");
	// printf("%d\n", len);

	// len = printf("decimal %d\n", 104210);
	// printf("%d\n", len);
	// len = ft_printf("decimal %d\n", 104210);
	// printf("%d\n", len);

	len = printf("decimal %d\n", -104210);
	printf("%d\n", len);
	len = ft_printf("decimal %d\n", -104210);
	printf("%d\n", len);

	// len = printf("Hello %x\n", 255);
	// printf("%d\n", len);
	// len = ft_printf("Hello %x\n", 255);
	// printf("%d\n", len);

	// len = printf("Hello %x\n", -42);
	// printf("%d\n", len);
	// len = ft_printf("Hello %x\n", -42);
	// printf("%d\n", len);
}