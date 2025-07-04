/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:57:31 by cmarrued          #+#    #+#             */
/*   Updated: 2025/02/10 17:57:32 by cmarrued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	if (is_sorted(*stack_a))
		return ;
	if (head->value > head->next->value)
		rotate_a(stack_a);
}

void	sort_3(t_stack **stack)
{
	if ((*stack)->index == get_min(stack, -1) && (*stack)->next->index
		!= get_min(stack, get_min(stack, get_min(stack, -1))))
	{
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if ((*stack)->index == get_min(stack, get_min(stack, -1)))
	{
		if ((*stack)->next->index == get_min(stack, -1))
			swap_a(stack);
		else
			reverse_rotate_a(stack);
	}
	else
	{
		if ((*stack)->next->index == get_min(stack, -1))
			rotate_a(stack);
		else
		{
			swap_a(stack);
			reverse_rotate_a(stack);
		}
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(*stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		reverse_rotate_a(stack_a);
	if (is_sorted(*stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (distance == 4)
		reverse_rotate_a(stack_a);
	if (is_sorted(*stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
