#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != *accept)
			return (n);
		s++;
		accept++;
		n++;
	}
	return (n);
}
