/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:06:55 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/10 12:22:19 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*tmp;
	size_t	s_start;
	size_t	len_s;

	if (!s)
		return (NULL);
	s_start = (size_t)start;
	len_s = 0;
	while (s[len_s])
		len_s++;
	if (s_start >= len_s)
		len = 0;
	else if (len_s - s_start < len)
		len = len_s - s_start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	tmp = substring;
	while (len--)
		*tmp++ = s[start++];
	*tmp = '\0';
	return (substring);
}
