/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:03:35 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:32:42 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*p;

	ch = (char)c;
	p = NULL;
	while (1)
	{
		if (ch == *s)
			p = (char *)s;
		if (*s++ == '\0')
			return (p);
	}
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", ft_strrchr("alicea", '\0'));
	printf("%s\n", strrchr("alicea", '\0'));
	return (0);
}
*/
