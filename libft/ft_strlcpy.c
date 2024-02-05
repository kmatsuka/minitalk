/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:19:16 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:22:16 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	tmp_dstsize;

	len_src = ft_strlen(src);
	tmp_dstsize = dstsize;
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	if (tmp_dstsize)
		*dst = '\0';
	return (len_src);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char	dst[6];
	//char	src[] = "hello";

	printf("%zu\n",strlcpy(NULL, NULL, 0));
	//printf("%s\n",dst);
	return (0);
}
*/
