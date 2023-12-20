/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:47:43 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/18 13:42:56 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (false);
	}
	return (true);
}

bool	stack_half_sorted(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next && temp->value < temp->next->value)
		temp = temp->next;
	if (temp->next)
		temp = temp->next;
	while (temp->next)
	{
		if (temp->value < temp->next->value && temp->value < stack->value)
			temp = temp->next;
		else
			return (false);
	}
	if (temp->value > stack->value)
		return (false);
	return (true);
}

void	sort_three(t_list **stack)
{
	t_list	*biggest_node;

	biggest_node = find_biggest_value(*stack);
	if (*stack == biggest_node)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	return ;
}

void	finalize_sorting(t_list **stack)
{
	t_list	*biggest;

	(*stack)->size = stack_len(*stack);
	biggest = find_biggest_value(*stack);
	set_current_position(stack);
	while (*stack)
	{
		if (stack_half_sorted(*stack))
		{
			if (biggest->above_med == true)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_sorted(*stack))
			break ;
	}
	return ;
}

void	handle_five(t_list **a, t_list **b)
{
	t_list	*smallest_a;

	set_len_pos(*a, *b);
	smallest_a = find_smallest_value(*a);
	if (smallest_a->above_med == true)
	{
		while (smallest_a->pos != 1)
		{
			ra(a);
			set_len_pos(*a, *b);
		}
	}
	else
	{
		while (smallest_a->pos != 1)
		{
			rra(a);
			set_len_pos(*a, *b);
		}
	}
}
