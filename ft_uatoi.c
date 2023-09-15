/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:55:42 by amonem            #+#    #+#             */
/*   Updated: 2023/07/10 05:24:09 by amonem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	intchecker(long result)
{
	if (result < -2147483648 || result > 2147483647)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	notallowedchar(char c)
{
	if ((c < '0' || c > '9') && c)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	checkifonlysign(char c)
{
	if (c == '\0')
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	ft_uatoi(const char *str)
{
	int		i;
	int		n;
	long	j;

	i = 0;
	j = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		checkifonlysign(str[i + 1]);
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = 10 * j + str[i] - 48;
		intchecker(j * n);
		i++;
	}
	notallowedchar(str[i]);
	return (j * n);
}
