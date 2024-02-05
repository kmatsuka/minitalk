/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/04 18:26:38 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	my_recieve_string_pid(int signum)
{
	static int	pid_c;
	static int	c;
	static int	i;

	if (i < 32)
	{
		pid_c = pid_c << 1;
		if (signum == SIGUSR1)
			pid_c = pid_c | 1;
		i++;
	}
	else
	{
		kill(pid_c, SIGUSR1);
		c = c << 1;
		if (signum == SIGUSR1)
			c = c | 1;
		if (++i - 32 == 8)
		{
			ft_putchar_fd(c, 1);
			c = 0;
			i = 0;
			pid_c = 0;
		}
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
	act1.sa_handler = my_recieve_string_pid;
	act2.sa_handler = my_recieve_string_pid;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
	return (0);
}
