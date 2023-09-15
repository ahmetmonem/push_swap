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

int	pushthesmall(t_stack **a, t_stack **b, int middle, int ag2)
{
	int	i;
	int	pushed;
	int	count;

	count = 0;
	pushed = 0;
	i = 0;
	while ((i++ < ag2) && (*a)-> next)
	{
		if ((*a)->x < middle && (*a)->next && ++pushed)
		{
			ft_p(a, b, 'b');
			count = counttheelem(*a);
			if (count <= 3)
			{
				sort(a);
				return (pushed);
			}
			if ((*b) && ((*b)->next) && (*b)->x < (middle * 80) / 100)
				ft_r(b, 'b');
		}
		else if ((*a)->next)
			ft_r(a, 'a');
	}
	return (pushed);
}

int	pushthebig(t_stack **a, t_stack **b, int middle, int ag)
{
	int	i;
	int	pushed;

	pushed = 0;
	i = 0;
	while (i++ < ag && (*a))
	{
		if ((*a)->x >= middle && ++pushed)
		{
			ft_p(a, b, 'a');
			if ((*b) && ((*b)->next) && (*b)->x < middle * 3 / 2)
				ft_r(b, 'a');
		}
		else
			if ((*a)->next)
				ft_r(a, 'b');
	}
	i = 0;
	if ((*a) && (*a)->next == NULL)
	{
		ft_p(a, b, 'a');
		pushed++;
	}
	return (pushed);
}

int	findpossmall(t_stack *list)
{
	int	small;
	int	pos;
	int	i;

	i = 1;
	pos = 1;
	small = (list)->x;
	list = list->next;
	while (list)
	{
		i++;
		if (list->x < small)
		{
			small = list->x;
			pos = i;
		}
		list = list->next;
	}
	return (pos);
}

int	findposbig(t_stack *list)
{
	int	big;
	int	pos;
	int	i;

	i = 1;
	pos = 1;
	big = (list)->x;
	list = list->next;
	while (list)
	{
		i++;
		if (list->x > big)
		{
			big = list->x;
			pos = i;
		}
		list = list->next;
	}
	return (pos);
}

void	my_bad_sortb(t_stack **a, t_stack **b, int ag, int j)
{
	int		i;
	int		agn;
	int		pofsmall;
	int		position;

	ag = counttheelem(*a) + 1;
	agn = counttheelem(*a);
	if (agn > 120)
		agn = (agn * 80) / 100;
	while ((*a)->next && j++ < agn)
	{
		i = 0;
		pofsmall = 0;
		position = 0;
		pofsmall = findposbig(*a) - 1;
		if (pofsmall >= (ag - 1) / 2)
			while (i++ < ((ag - 1) - pofsmall))
				ft_rr(a, 'b');
		else if (pofsmall < (ag - 1) / 2)
			while (i++ < pofsmall)
				ft_r(a, 'b');
		ft_p(a, b, 'a');
		ag--;
	}
}
