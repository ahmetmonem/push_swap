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

void	errormassage(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int ag, char *arg[])
{
	t_arguments	*str;
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	if (ag == 1)
		return (0);
	if (is_empty(arg))
		errormassage();
	str = bringallargs(arg, ag, 1, NULL);
	a = liststarter(str);
	ag = counttheelem(a) + 1;
	checkrepeat(a);
	if (!(checkunsorted(a)))
		return (0);
	if (ag <= 4)
		sort(&a);
	if (!(checkunsorted(a)))
		return (0);
	my_first_sort(&a, &b, ag);
	if (!(checkunsorted(a)))
		return (0);
	my_bad_sort(&a, &b, ag, 0);
}
