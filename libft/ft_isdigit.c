/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:18:16 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/09/29 12:41:16 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	for (int i = -600; i < 601; i++){
		if (ft_isdigit(i) != isdigit(i))
		{
			printf("FALSE\n");
			return (1);
		}
	}
	printf("SUCCESS\n");
	return (0);
}
*/
