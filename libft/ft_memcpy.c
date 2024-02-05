/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:41 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:12:28 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	//char	dst[] = "hello";
	char	src[] = "world";

	printf("%s\n", (char *)ft_memcpy(NULL, src, 1));
	return (0);
}
*/
