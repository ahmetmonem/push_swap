/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:41:57 by amonem            #+#    #+#             */
/*   Updated: 2023/07/03 19:02:39 by amonem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *str)
{
	char	*tbd;
	char	*original;
	int		s;

	s = ft_strlen(str);
	tbd = (char *)malloc(s + 1);
	original = tbd;
	if (tbd == NULL)
		return (NULL);
	while (*str)
	{
		*tbd = *str;
		tbd++;
		str++;
	}
	*tbd = '\0';
	return (original);
}
