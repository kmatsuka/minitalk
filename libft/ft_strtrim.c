/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:58:45 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 13:54:42 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_is_set(char	const *s, int c);
static char	*my_strndup(const char *s, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && my_is_set(set, s1[start]))
		start++;
	end = 0;
	if (ft_strlen(s1) > 0)
		end = ft_strlen(s1) - 1;
	while (end > 0 && my_is_set(set, s1[end]))
		end--;
	len = 0;
	if (end >= start)
		len = end - start + 1;
	str = my_strndup(&s1[start], len);
	return (str);
}

static char	*my_strndup(const char *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}

static int	my_is_set(char	const *s, int c)
{
	while (s && *s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char *s1 = "1234567890";
	char *s2 = NULL;

	printf("%s\n", ft_strtrim(s1, s2));
	return (0);
}
*/
