/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:17:39 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/13 18:21:00 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	my_isupper(int c);
static int	my_islower(int c);

int	ft_isalpha(int c)
{
	return (my_isupper(c) || my_islower(c));
}

static int	my_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

static int	my_islower(int c)
{
	return ('a' <= c && c <= 'z');
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	for (int i = -600; i < 601; i++){
		if (ft_isalpha(i) != isalpha(i))
		{
			printf(":FALSE\n");
			return (1);
		}
	}
	printf("SUCCESS\n");
	return (0);
}
*/
