/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 04:19:55 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/04 18:23:26 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_recieve_string(int signum)
{
	static int	c;
	static int	i;

	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" is PID.\n", 1);
	sigemptyset(&act1.sa_mask);
	sigemptyset(&act2.sa_mask);
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act2.sa_mask, SIGUSR1);
	act1.sa_handler = my_recieve_string;
	act2.sa_handler = my_recieve_string;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
	return (0);
}
