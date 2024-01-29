/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:54:41 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/29 18:44:59 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

void	bit_rec(int sig)
{
	static int	i = 0;
	static char	c;

	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1 | 0;
	i++;
	if (i >= 8)
	{
		i = 0;
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, bit_rec);
	signal(SIGUSR2, bit_rec);
	while (1)
		pause();
}
