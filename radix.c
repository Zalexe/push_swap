/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:17:52 by cmarrued          #+#    #+#             */
/*   Updated: 2025/02/11 12:17:53 by cmarrued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	radix_sort_stackb(t_stack **stack_a, t_stack **stack_b,
			int max_bits, int i)
{
	int	b_size;

	b_size = ft_lstsize(*stack_b);
	while (b_size-- && i <= max_bits && !is_sorted(*stack_a))
	{
		if ((((*stack_b)->index >> i) & 1) == 0)
			rotate_b(stack_b);
		else
			push_a(stack_a, stack_b);
	}
	if (is_sorted(*stack_a))
		while (*stack_b)
			push_a(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;
	int	max_bits;

	i = -1;
	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while (size > 1 && ++max_bits)
		size /= 2;
	while (++i <= max_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size-- && !is_sorted(*stack_a))
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		radix_sort_stackb(stack_a, stack_b, max_bits, i + 1);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}
