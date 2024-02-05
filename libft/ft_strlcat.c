/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:20:21 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:24:32 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	len_total;

	len_src = ft_strlen(src);
	len_dst = 0;
	if (dst)
		len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	len_total = len_dst + len_src;
	dstsize -= len_dst;
	while (*src && dstsize-- > 1)
		dst[len_dst++] = *src++;
	dst[len_dst] = '\0';
	return (len_total);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char	dst[6];
	char	src[] = "hello";

	printf("%zu\n",ft_strlcat(NULL, src, 1));
	return (0);
}
*/
