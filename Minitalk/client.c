/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:52:58 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/27 17:02:00 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

void	ft_bitsignal(int pid, char x)
{
	int		c;

	c = 7;
	while (c >= 0)
	{
		if (x >> c & 1)
			kill(pid, SIGUSR1);
		else if (!(x >> c & 0))
			kill(pid, SIGUSR2);
		usleep(250);
		c--;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 3 && (ft_atoi(argv[1]) > 0))
	{
		i = 0;
		while (argv[2][i])
		{
			ft_bitsignal(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		ft_bitsignal(ft_atoi(argv[1]), '\n');
	}
	else
	{
		write(1, "Check the number of arguments. It must be 3", 47);
		write(1, "(Also the PID must be a positive number!)", 42);
		return (1);
	}
	return (0);
}
