/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:09:14 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/29 18:45:02 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
	long	result;
	int		n;

	n = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * n;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		str++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	number;

	number = (long)nb;
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10);
		ft_putchar(number % 10 + 48);
	}
	else
		ft_putchar(number + '0');
}
