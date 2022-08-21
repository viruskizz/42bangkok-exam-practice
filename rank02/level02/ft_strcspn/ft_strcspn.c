#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	n;
	const char	*tmp;

	n = 0;
	while (*s)
	{
		tmp = reject;
		while (*tmp)
		{
			if (*s == *tmp)
				return (n);
			tmp++;
		}
		n++;
		s++;
	}
	return (n);
}
