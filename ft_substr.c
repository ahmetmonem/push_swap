/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:30:40 by amonem            #+#    #+#             */
/*   Updated: 2023/07/15 13:47:26 by amonem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	alen;

	alen = len;
	if (start < 0 || start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		alen = ft_strlen(s) - start;
	i = 0;
	substr = (char *)malloc(alen + 1);
	if (substr == NULL)
		return (NULL);
	while (alen > 0 && *s)
	{
		substr[i] = s[start + i];
		i++;
		alen--;
	}
	substr[i] = '\0';
	return (substr);
}
