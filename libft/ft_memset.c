/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:19:05 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 12:58:56 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len--)
		*(p + len) = (unsigned char)ch;
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char	s[] = "hello";

    printf("%s\n",(char *)ft_memset(s, '0', 4));
    return (0);
}
*/
