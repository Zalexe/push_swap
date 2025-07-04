/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarrued <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:32 by cmarrued          #+#    #+#             */
/*   Updated: 2025/01/28 18:26:33 by cmarrued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;	
	int				index;
	struct s_node	*next;
}	t_stack;

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort_stackb(t_stack **stack_a, t_stack **stack_b,
			int maxbits, int i);
//movement
void	swap(t_stack **stack);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);

//small sort
int		get_min(t_stack **stack, int val);
void	sort_2(t_stack **stack_a);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

//utils
t_stack	*create_stack(int *numbers, int size);
void	clear_stack(t_stack **stack);
void	clear(t_stack **stack, int *numbers);
void	index_stack(t_stack **stack);
void	free_strings(int *numbers, char **strings, int i);
int		get_distance(t_stack **stack, int index);
int		is_sorted(t_stack *stack);
int		ft_isdigit(int c);
int		is_valid_integer(char *str);
int		valid_stack(t_stack *stack);
int		*parse_arguments(int argc, char **argv, int *size, int i);
int		*parse_arguments_string(int k, char **argv, int *size, int i);
long	ft_atol(const char *str);

//libft
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_countword(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_lstsize(t_stack *lst);
#endif 
