/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:50:16 by araiva            #+#    #+#             */
/*   Updated: 2022/05/17 18:50:17 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb);
int		next_prime(int nb, int limit);
int		is_prime(int nb);

int	main(int argc, char *argv[])
{
	int		nb;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		fprime(nb);
	}
	printf("\n");
}

void	fprime(int nb)
{
	int		i;
	int		sign;

	i = 2;
	sign = 0;
	if (nb < 0)
		return ;
	if (nb <= 3)
	{
		printf("%d", nb);
		return ;
	}
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			if (sign)
				printf("*");
			printf("%d", i);
			sign = 1;
			nb = nb / i;
		}
		else
			i = next_prime(++i, nb);
	}
}

int	next_prime(int nb, int limit)
{
	int		i;

	i = nb;
	while (!is_prime(i) && i <= limit)
		i++;
	return (i);
}

int	is_prime(int nb)
{
	int		i;

	i = 2;
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
