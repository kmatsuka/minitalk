/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:48:50 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/13 18:21:40 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	while (s1 && s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2 && s2[len_s2])
		len_s2++;
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (len_s1--)
		*tmp++ = *s1++;
	while (len_s2--)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}
