/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:54:23 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/13 15:38:37 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_count;
	char	*p;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	size_count = size * count;
	p = (char *)malloc(size_count);
	if (!p)
		return (NULL);
	while (size_count--)
		p[size_count] = 0;
	return ((void *)p);
}
/*
#include <stdio.h>
int main(void)
{
	char	*p;
	
	p = ft_calloc(SIZE_MAX, SIZE_MAX);
	printf("s:%s\n",p);
	return (0);
}
*/
