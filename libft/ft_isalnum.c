/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:17:21 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 12:42:01 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	for (int i = -600; i < 601; i++){
		if (ft_isalnum(i) != isalnum(i))
		{
			printf("FALSE\n");
			return (1);
		}
	}
	printf("SUCCESS\n");
	return (0);
}
*/
