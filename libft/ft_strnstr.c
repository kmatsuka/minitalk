/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:26:24 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:42:02 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	char	*tmp_haystack;

	len_needle = ft_strlen(needle);
	tmp_haystack = (char *)haystack;
	while (len && *haystack)
	{
		if (haystack - tmp_haystack + len_needle > len)
			break ;
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	if (len_needle == 0)
		return ((char *)haystack);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char	hay[] = "";
	char	need[] = "";

	printf("%s\n",ft_strnstr(NULL, need, 0));
	printf("%s\n",strnstr(NULL, need, 0));
	return (0);
}
*/
