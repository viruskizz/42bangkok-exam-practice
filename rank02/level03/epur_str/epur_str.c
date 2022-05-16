/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:05:21 by araiva            #+#    #+#             */
/*   Updated: 2022/05/16 14:05:24 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_trim(char *str);
int		is_delimited(char c);
int		is_printable(char c);

int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_trim(argv[1]);
	ft_putchar('\n');
	return (0);
}

void	print_trim(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_delimited(str[i]) && is_delimited(str[i - 1]))
			i++;
		else
			ft_putchar(str[i++]);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_delimited(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	else
		return (0);
}

int	is_printable(char c)
{
	if (c < 32 || c > 127)
		return (0);
	else
		return (1);
}
