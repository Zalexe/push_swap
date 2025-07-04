/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:25 by cmarrued          #+#    #+#             */
/*   Updated: 2025/01/28 18:26:28 by cmarrued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap( t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size <= 1 || is_sorted(*stack_a))
		;
	else if (size <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

t_stack	*create_stack(int *numbers, int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	i = size - 1;
	stack = NULL;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			clear_stack(&stack);
			return (NULL);
		}
		new_node->value = numbers[i--];
		new_node->index = -1;
		new_node->next = stack;
		stack = new_node;
	}
	return (stack);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	clear(t_stack **stack, int *numbers)
{
	clear_stack(stack);
	free(numbers);
}

int	main(int argc, char **arg)
{
	int		size;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		numbers = parse_arguments_string(ft_countword(arg[1], ' '),
				arg, &size, 0);
	else
		numbers = parse_arguments(argc, arg, &size, 1);
	if (!numbers)
		return (write(2, "Error\n", 6));
	stack_a = create_stack(numbers, size);
	if (!stack_a || !valid_stack(stack_a))
	{
		clear(&stack_a, numbers);
		return (write(2, "Error\n", 6));
	}
	index_stack(&stack_a);
	push_swap(&stack_a, &stack_b, size);
	clear(&stack_a, numbers);
	return (0);
}
