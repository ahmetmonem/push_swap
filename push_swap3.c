/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:39:43 by amonem            #+#    #+#             */
/*   Updated: 2023/08/23 16:39:45 by amonem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkunsorted(t_stack *list)
{
	while (list->next)
	{
		if (list->x > list->next->x)
			return (1);
		list = list->next;
	}
	return (0);
}

void	sort(t_stack **a)
{
	t_stack	*start;

	while (checkunsorted(*a))
	{
		start = *a;
		if (start->x > start->next->x)
			ft_s(start, 'a');
		while (start->next->next)
		{
			start = start->next;
			if (start->x > start->next->x)
				ft_rr(a, 'a');
			break ;
		}
	}
}

int	findthesmall(t_stack *list, int ag)
{
	int	small;

	small = list->x;
	if (ag == 1)
		return (small);
	while (list->next)
	{
		list = list->next;
		if (small > list->x)
			small = list->x;
	}
	return (small);
}

int	findthegig(t_stack *list, int small)
{
	while (list)
	{
		if (small < list->x)
			small = list->x;
		list = list->next;
	}
	return (small);
}

int	findthemiddle(t_stack *list, int ag2, int i)
{
	int		small;
	t_stack	*liststart;
	int		newsmall;

	liststart = list;
	small = findthesmall(list, ag2);
	if (ag2 > 101)
		ag2 = ag2 / 2;
	if (ag2 < 101 && ag2 > 30)
		ag2 = ag2 * 34 / 50;
	while (i++ < ag2 / 2)
	{
		list = liststart;
		newsmall = small;
		small = findthegig(list, small);
		list = liststart;
		while (list)
		{
			if (newsmall < list->x && small > list->x)
				small = list->x;
			list = list->next;
		}
	}
	return (small);
}
