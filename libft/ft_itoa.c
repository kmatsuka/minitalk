/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:53:49 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 15:00:29 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_measure_size(int n);
static void		my_make_intmin(char *str, int n, size_t size);
static void		my_make_numstr(char *str, int n, size_t size);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	if (n == INT_MIN)
	{
		size = 11;
		str = (char *)malloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		my_make_intmin(str, n, size);
	}
	else
	{
		size = my_measure_size(n);
		str = (char *)malloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		my_make_numstr(str, n, size);
	}
	return (str);
}

static size_t	my_measure_size(int n)
{
	size_t	size;

	if (n == INT_MIN)
		return (0);
	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	my_make_intmin(char *str, int n, size_t size)
{
	str[size] = '\0';
	str[0] = '-';
	str[--size] = '0' - (n % 10);
	n = -(n - n % 10) / 10;
	while (size-- > 1)
	{
		str[size] = '0' + (n - n / 10 * 10);
		n = n / 10;
	}
}

static void	my_make_numstr(char *str, int n, size_t size)
{
	size_t	end;

	str[size] = '\0';
	end = 0;
	if (n < 0)
	{
		str[0] = '-';
		end++;
		n = -n;
	}
	while (size-- > end)
	{
		str[size] = '0' + (n - n / 10 * 10);
		n = n / 10;
	}
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s\n",ft_itoa(-2147483648));
	return (0);
}
*/
