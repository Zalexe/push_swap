/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:00:06 by cmarrued          #+#    #+#             */
/*   Updated: 2025/02/01 17:00:08 by cmarrued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if ((!ft_isdigit(str[i]) && !ft_strchr("+-", str[i]))
			|| (ft_strchr("+-", str[i]) && i != 0))
			return (0);
		i++;
	}
	return (1);
}

int	*parse_arguments_string(int k, char **argv, int *size, int i)
{
	int		*numbers;
	int		j;
	long	number;
	char	**args;

	j = 0;
	args = ft_split(argv[1], ' ');
	numbers = malloc(sizeof(int) * (k));
	if (!numbers)
		return (NULL);
	while (i < k)
	{
		if (!is_valid_integer(args[i]))
			return (free_strings(numbers, args, k), NULL);
		number = ft_atol(args[i++]);
		if (number < INT_MIN || number > INT_MAX)
			return (free_strings(numbers, args, k), NULL);
		numbers[j++] = (int)number;
	}
	*size = j;
	return (free_strings(0, args, k), numbers);
}

int	*parse_arguments(int argc, char **argv, int *size, int i)
{
	int		*numbers;
	int		j;
	long	number;

	j = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]))
		{
			free(numbers);
			return (NULL);
		}
		number = ft_atol(argv[i++]);
		if (number < INT_MIN || number > INT_MAX)
		{
			free(numbers);
			return (NULL);
		}
		numbers[j++] = (int)number;
	}
	*size = j;
	return (numbers);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	valid_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->value == next->value)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}
