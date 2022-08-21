#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject);

int	main(void)
{
	char	str[20];
	char	r[20];

	strcpy(str, "Hello"); strcpy(r, "oa");
	printf("%s < %s : %ld\n", str, r, strcspn(str, r));
	printf("%s < %s : %ld\n", str, r, ft_strcspn(str, r));
	strcpy(str, "Hello"); strcpy(r, "oe");
	printf("%s < %s : %ld\n", str, r, strcspn(str, r));
	printf("%s < %s : %ld\n", str, r, ft_strcspn(str, r));
	strcpy(str, "Hello"); strcpy(r, "x");
	printf("%s < %s : %ld\n", str, r, strcspn(str, r));
	printf("%s < %s : %ld\n", str, r, ft_strcspn(str, r));
	return (0);
}
