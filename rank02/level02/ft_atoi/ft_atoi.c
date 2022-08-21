int	ft_atoi(const char *str)
{
	int	nb;
	int	prefix;
	
	nb = 0;
	prefix = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		prefix = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * prefix);
}
