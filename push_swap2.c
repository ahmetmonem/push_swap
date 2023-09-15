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

void	ft_p(t_stack **from_list, t_stack **to_list, char c)
{
	t_stack	*temp;

	temp = *from_list;
	*from_list = (*from_list)->next;
	temp->next = (*to_list);
	*to_list = temp;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_s(t_stack *list, char c)
{
	int	temp;

	temp = list->x;
	list->x = list->next->x;
	list->next->x = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_rr(t_stack **list, char c)
{
	t_stack	*temps;
	t_stack	*templ;

	temps = *list;
	while ((*list)->next->next)
		*list = (*list)->next;
	templ = (*list)->next;
	templ->next = temps;
	(*list)->next = NULL;
	*list = templ;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_r(t_stack **list, char c)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *list;
	last = (*list)->next;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = temp;
	temp->next = NULL;
	*list = last;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	checkrepeat(t_stack *list)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = list;
	while (list)
	{
		temp = list->next;
		i = 0;
		while (temp)
		{
			if (temp->x == list->x)
				i++;
			temp = temp->next;
		}
		if (i != 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		list = list->next;
	}
}
