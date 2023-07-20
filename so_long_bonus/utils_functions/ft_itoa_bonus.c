/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:09:28 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/04/08 11:09:29 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static long	lenint(long n)
{
	long	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	n2;
	long	count;
	char	*p;

	n2 = n;
	count = lenint(n2);
	p = malloc((count + 1) * sizeof(char));
	if (!p)
		return (0);
	if (n < 0)
	{
		n2 = n2 * -1;
		p[0] = '-';
	}
	p[count] = '\0';
	count--;
	if (n == 0)
		p[count] = '0';
	while (n2 > 0)
	{
		p[count] = (n2 % 10) + 48;
		n2 /= 10;
		count--;
	}
	return (p);
}
