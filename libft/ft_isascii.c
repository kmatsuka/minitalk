/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:17:59 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 12:42:50 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	for (int i = -600; i < 601; i++){
		if (ft_isascii(i) != isascii(i))
		{
			printf("FALSE\n");
			return (1);
		}
	}
	printf("SUCCESS\n");
	return (0);
}
*/
