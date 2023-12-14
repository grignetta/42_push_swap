/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:35:47 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 20:09:53 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	(*a)->size = stack_len(*a);
	while ((*a)->size > 3)
	{
		if (stack_sorted(*a))
			break ;
		if (stack_half_sorted(*a))
			break ;
		if ((*a)->size == 5)
			handle_five(a, b);
		push_to_b(a, b);
		set_len_pos(*a, *b);
		set_cost_a(a, b);
	}
	if ((*a)->size > 3)
		finalize_sorting(a);
	else
		sort_three(a);
	while (*b)
		push_to_a(a, b);
	finalize_sorting(a);
	return ;
}

void	push_to_a(t_list **a, t_list **b)
{
	t_list				*b_to_push;
	t_list				*bigger_a;
	t_algorithm_params	params;

	set_len_pos(*a, *b);
	set_cost_b(a, b);
	b_to_push = node_to_push(b);
	bigger_a = find_bigger(*a, b_to_push);
	if (!bigger_a)
		bigger_a = find_smallest_value(*a);
	params.sizea = (*a)->size;
	params.sizeb = (*b)->size;
	params.posb = b_to_push->pos;
	params.posa = bigger_a->pos;
	params.to_push = bigger_a;
	params.receive_pos = b_to_push;
	b_to_push->algorithm(a, b, params.to_push, params.receive_pos);
	return (pa(a, b));
}

void	set_params(t_list **a, t_list **b, t_list *a_to_push, t_list *smaller_b)
{
	t_algorithm_params	params;

	params.sizea = (*a)->size;
	params.sizeb = (*b)->size;
	params.posa = a_to_push->pos;
	params.posb = smaller_b->pos;
	params.to_push = a_to_push;
	params.receive_pos = smaller_b;
	a_to_push->algorithm(a, b, params.to_push, params.receive_pos);
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*a_to_push;
	t_list	*smaller_b;

	if (!*b)
		return (pb(b, a));
	if ((*b)->next == NULL)
	{
		if ((*a)->value < (*b)->value)
			return (pb(b, a), sb(b));
		return (pb(b, a));
	}
	set_len_pos(*a, *b);
	set_cost_a(a, b);
	a_to_push = node_to_push(a);
	smaller_b = find_smaller(a_to_push, *b);
	if (!smaller_b)
		smaller_b = find_biggest_value(*b);
	set_params(a, b, a_to_push, smaller_b);
	return (pb(b, a));
}

t_list	*node_to_push(t_list **stack)
{
	t_list	*to_push;

	if (stack == NULL)
		return (NULL);
	to_push = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->next->cost < to_push->cost)
			to_push = (*stack)->next;
		stack = &(*stack)->next;
	}
	return (to_push);
}
