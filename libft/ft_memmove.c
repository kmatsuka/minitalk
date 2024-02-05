/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:52 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:14:13 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
			p_dst[len] = p_src[len];
	}
	else
	{
		while (len--)
			*p_dst++ = *p_src++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	//char	dst[] = "hello";
	char	src[] = "world";

	printf("%s\n", (char *)ft_memmove(NULL, src, 1));
	return (0);
}
*/
