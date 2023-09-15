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

void	my_bad_sort(t_stack **a, t_stack **b, int ag, int j)
{
	int		i;
	int		pofsmall;
	int		position;

	while ((*a)->next && (checkunsorted(*a)))
	{
		i = 0;
		pofsmall = 0;
		position = 0;
		pofsmall = findpossmall(*a) - 1;
		if (pofsmall >= (ag - 1) / 2)
			while (i++ < ((ag - 1) - pofsmall))
				ft_rr(a, 'a');
		else if (pofsmall < (ag - 1) / 2)
			while (i++ < pofsmall)
				ft_r(a, 'a');
		ft_p(a, b, 'b');
		j++;
		ag--;
	}
	i = 0;
	while (i++ < j)
		ft_p(b, a, 'a');
}

int	checkifremainok(t_stack *a, t_stack *b)
{
	int	small;

	small = findthesmall(a, counttheelem(a));
	while (b)
	{
		if (small < b->x)
			return (0);
		b = b->next;
	}
	return (1);
}

void	my_first_sort(t_stack **a, t_stack **b, int ag)
{
	int	middle;
	int	pushed;
	int	ag2;

	ag2 = counttheelem(*a);
	while (1)
	{
		middle = findthemiddle(*a, ag2, 0);
		pushed = pushthesmall(a, b, middle, ag2);
		ag2 = counttheelem(*a);
		if (counttheelem(*a) <= 3 && checkifremainok(*a, *b))
			break ;
		if (counttheelem(*a) == 0)
			break ;
	}
	my_bad_sortb(b, a, ag, 0);
	ag2 = counttheelem(*b);
	while (1)
	{
		middle = findthemiddle(*b, ag2, 0);
		pushed = pushthebig(b, a, middle, ag2);
		ag2 = ag2 - pushed;
		if (ag2 == 0)
			break ;
	}
}

int	is_empty(char **str)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		check = 1;
		if (!(str[i][j]))
			return (1);
		while (str[i][j])
		{
			if (str[i][j] != ' ')
				check = 0;
			j++;
		}
		if (check == 1)
			return (1);
		i++;
	}
	return (0);
}
