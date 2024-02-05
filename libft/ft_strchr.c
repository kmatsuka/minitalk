/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:23:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 14:46:15 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s || ch == '\0')
	{
		if (ch == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", ft_strchr("hello", 'l' + 256));
	printf("%s\n", strchr("hello", 'l' + 256));
	return (0);
}
*/
