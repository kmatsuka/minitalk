/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:22:55 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 15:10:18 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_count_words(char const *s, char c);
static char		*my_strndup(const char *s, size_t len);
static char		**my_deploy_w(char const *s, char c, char **str, size_t *count);

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc((my_count_words(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	count = 0;
	if (my_deploy_w(s, c, str, &count) == NULL)
		return (NULL);
	str[count] = NULL;
	return (str);
}

static char	**my_deploy_w(char const *s, char c, char **str, size_t *count)
{
	size_t	ind;
	size_t	tmp;

	ind = 0;
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		tmp = ind;
		while (s[ind] && s[ind] != c)
			ind++;
		if (s[tmp])
		{
			str[(*count)++] = my_strndup(&s[tmp], ind - tmp);
			if (str[*count - 1] == NULL)
			{
				while (--(*count) >= 0)
					free(str[*count]);
				free(str);
				return (NULL);
			}
		}
	}
	return (str);
}

static size_t	my_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (*s)
	{
		i = 1;
		while (s[i])
		{
			if (s[i] != c && s[i - 1] == c)
				count++;
			i++;
		}
	}
	if (s[0] && s[0] != c)
		count++;
	return (count);
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
/*
int	main(void)
{
	char	*s = "      split       this for   me  !       ";
	char	c = ' ';
	char	**str;

	str = ft_split(s, c);
	for (int i=0; i<5; i++){
		printf("%s\n",str[i]);
	}
	return (0);
}
*/
