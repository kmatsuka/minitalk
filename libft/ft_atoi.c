/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:35:10 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/13 12:40:49 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (n * sign > LONG_MAX / 10 || (n * sign == LONG_MAX / 10
				&& *str - '0' > LONG_MAX - LONG_MAX / 10 * 10))
			return ((int)LONG_MAX);
		if (n * sign < LONG_MIN / 10 || (n * sign == LONG_MIN / 10
				&& -(*str - '0') < LONG_MIN - LONG_MIN / 10 * 10))
			return ((int)LONG_MIN);
		n = (n * 10) + (*str - '0');
		str++;
	}
	return ((int)(n * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*s = "-42";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}
*/
