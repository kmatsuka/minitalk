/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:28:43 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/04 17:43:09 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_send_string(pid_t pid, char *str)
{
	int	digit;

	while (*str)
	{
		digit = 8;
		while (--digit >= 0)
		{
			if (*str & (1 << digit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		str++;
	}
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
	pid_t	pid;

	if (my_handle_error(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	my_send_string(pid, argv[2]);
	return (0);
}
