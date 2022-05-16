/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:45:53 by araiva            #+#    #+#             */
/*   Updated: 2022/05/16 20:45:54 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	my_print(char *str);
int		count_space(char *str);

int	main(int argc, char *argv[])
{
	if (argc == 2)
		my_print(argv[1]);
	ft_putchar('\n');
}

void	my_print(char *str)
{
	int		sp;
	int		nsp;

	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		sp = 1;
		if (*str == ' ' || *str == '\t')
		{
			sp = count_space(str);
			nsp = 0;
			if (!str[sp])
				return ;
			while (nsp++ <= 3)
				ft_putchar(' ');
		}
		else
			ft_putchar(*str);
		str = str + sp;
	}
}

int	count_space(char *str)
{
	int		i;

	i = 0;
	while (*str == ' ' || *str == '\t')
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
