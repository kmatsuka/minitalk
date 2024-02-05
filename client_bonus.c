/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:39 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/04 17:46:35 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	my_send_string_pid(pid_t pid_s, char *str, pid_t pid_c)
{
	int	digit_pid;
	int	digit_str;

	while (*str)
	{
		digit_pid = 32;
		while (--digit_pid >= 0)
		{
			if (pid_c & (1 << digit_pid))
				kill(pid_s, SIGUSR1);
			else
				kill(pid_s, SIGUSR2);
			usleep(50);
		}
		digit_str = 8;
		while (--digit_str >= 0)
		{
			if (*str & (1 << digit_str))
				kill(pid_s, SIGUSR1);
			else
				kill(pid_s, SIGUSR2);
			usleep(50);
		}
		str++;
	}
}

void	my_receive_response(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("Receive a signal from server.\n", 1);
}

int	my_check_pid(char *pid)
{
	int	n;

	n = 0;
	while ('0' <= *pid && *pid <= '9')
	{
		if (n > INT_MAX / 10 || (n == INT_MAX / 10
				&& *pid - '0' > INT_MAX - INT_MAX / 10 * 10))
			return (-1);
		n = (n * 10) + (*pid - '0');
		pid++;
	}
	return (0);
}

int	my_handle_error(int argc, char *argv[])
{
	size_t	ind;

	if (argc != 3)
	{
		ft_putstr_fd("Must have two arguments.\n", 1);
		return (1);
	}
	ind = 0;
	while (argv[1][ind])
	{
		if (!ft_isdigit(argv[1][ind++]))
		{
			ft_putstr_fd("Pid must be a positive integer.\n", 1);
			return (1);
		}
	}
	if (my_check_pid(argv[1]))
	{
		ft_putstr_fd("Pid must be a positive integer.\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid_s;

	if (my_handle_error(argc, argv))
		return (1);
	pid_s = ft_atoi(argv[1]);
	signal(SIGUSR1, my_receive_response);
	my_send_string_pid(pid_s, argv[2], getpid());
	return (0);
}
