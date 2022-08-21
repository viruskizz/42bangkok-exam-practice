#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main()
{
	char s1[100]; char s2[100];
	strcpy(s1, "hello"); strcpy(s2, "hello");
	printf("%d == %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	strcpy(s1, "helloxxx"); strcpy(s2, "hello");
	printf("%d == %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	strcpy(s1, "hello"); strcpy(s2, "helloxx");
	printf("%d == %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	strcpy(s1, "hello"); strcpy(s2, "hel");
	printf("%d == %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	return (0);
}
