#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept);

int	main(void)
{
	char	str[20];
	char	acc[20];

	strcpy(str, "hello"); strcpy(acc, "hello");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "hello");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "world");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "worldx");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "w");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "wor");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	strcpy(str, "world hello"); strcpy(acc, "world hello");
	printf("+%s < %s : %ld\n", str, acc, strspn(str, acc));
	printf("-%s < %s : %ld\n", str, acc, ft_strspn(str, acc));
	return (0);
}
