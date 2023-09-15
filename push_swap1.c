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

void	helpforbring(t_arguments **current, t_arguments **temp, t_arguments **a)
{
	if (*current == NULL)
	{
		*current = *temp;
		*a = *current;
	}
	else
	{
		(*current)->next = *temp;
		*current = (*current)->next;
	}
}

t_arguments	*bringallargs(char **arg, int ag, int i, t_arguments *current)
{
	t_arguments	*a;
	t_arguments	*temp;
	char		**strs;
	int			j;

	while (i < ag)
	{
		strs = ft_split(arg[i++], ' ');
		j = 0;
		if (strs[j])
		{
			while (strs[j])
			{
				temp = malloc(sizeof(struct arguments));
				temp->argi = strs[j++];
				helpforbring(&current, &temp, &a);
			}
		}
		else
			exit(0);
		free(strs);
	}
	current->next = NULL;
	return (a);
}

t_stack	*liststarter(t_arguments *thelastarg)
{
	t_stack	*current;
	t_stack	*a;
	t_stack	*temp;

	current = NULL;
	while (thelastarg)
	{
		temp = malloc(sizeof(struct stack));
		temp->x = ft_uatoi(thelastarg->argi);
		if (current == NULL)
		{
			current = temp;
			a = current;
		}
		else
		{
			current->next = temp;
			current = temp;
		}
		thelastarg = thelastarg->next;
	}
	return (a);
}

int	counttheelem(t_stack *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
