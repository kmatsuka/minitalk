/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:30 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 14:02:26 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	for (int i = -600; i < 601; i++){
		if (ft_isprint(i) != isprint(i))
		{
			printf("FALSE\n");
			return (1);
		}
	}
	printf("SUCCESS\n");
	return (0);
}
*/
