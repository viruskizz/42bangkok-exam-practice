#include <unistd.h>
#include <stdio.h>

void	print_sum_prime(int nb);
int		is_prime(int nb);
int		ft_atoi(char *str);
int		ft_putnbr(int nb);
void	ft_putchar(char c);
int		my_writenbr(int nb);

int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_sum_prime(ft_atoi(argv[1]));
	else
		ft_putchar('0');
	ft_putchar('\n');
}

void	print_sum_prime(int nb)
{
	int	sum;
	int i;

	i = 2;
	sum = 0;
	if(nb < 0)
		nb = 0;
	while (i <= nb)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
}

int		is_prime(int nb)
{
	int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int nb;

	nb = 0;
	while (*str)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb);
}

int	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
		my_writenbr(nb);
	return (0);
}

int	my_writenbr(int nb)
{
	if (nb == 0)
		return (0);
	else
	{
		my_writenbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
