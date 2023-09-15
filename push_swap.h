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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				x;
	struct stack	*next;
}					t_stack;

typedef struct arguments
{
	char				*argi;
	struct arguments	*next;
}						t_arguments;

int			ft_uatoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
void		my_bad_sort(t_stack **a, t_stack **b, int ag, int j);
void		my_first_sort(t_stack **a, t_stack **b, int ag);
int			pushthesmall(t_stack **a, t_stack **b, int middle, int ag2);
int			pushthebig(t_stack **a, t_stack **b, int middle, int ag);
int			findpossmall(t_stack *list);
int			findposbig(t_stack *list);
void		my_bad_sortb(t_stack **a, t_stack **b, int ag, int j);
int			checkunsorted(t_stack *list);
void		sort(t_stack **a);
int			findthesmall(t_stack *list, int ag);
int			findthegig(t_stack *list, int small);
int			findthemiddle(t_stack *list, int ag2, int i);
void		ft_p(t_stack **from_list, t_stack **to_list, char c);
void		ft_s(t_stack *list, char c);
void		ft_rr(t_stack **list, char c);
void		ft_r(t_stack **list, char c);
void		freelist(t_stack *list);
void		checkrepeat(t_stack *list);
t_arguments	*bringallargs(char **arg, int ag, int i, t_arguments *current);
t_stack		*liststarter(t_arguments *thelastarg);
int			counttheelem(t_stack *list);
int			is_empty(char **str);

#endif
