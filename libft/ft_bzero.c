/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:16:57 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 14:56:39 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*(p + n) = 0;
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	s[] = "hello";

	ft_bzero(&s[1], 2);
	printf("%s\n", s);
	return (0);
}
*/
