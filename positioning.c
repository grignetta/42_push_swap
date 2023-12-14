/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:02:51 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 18:24:34 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_len_pos(t_list *a, t_list *b)
{
	if (a)
	{
		set_current_position(&a);
		a->size = stack_len(a);
	}
	if (b)
	{
		set_current_position(&b);
		b->size = stack_len(b);
	}
	return ;
}

void	set_current_position(t_list **stack)
{
	int		i;
	t_list	*temp;
	int		median;
	int		len;

	len = stack_len(*stack);
	temp = *stack;
	i = 1;
	if (temp == NULL)
		return ;
	if (len % 2 == 0)
		median = len / 2;
	else
		median = (len / 2) + 1;
	while (temp)
	{
		temp->pos = i;
		if (i <= median)
			temp->above_med = true;
		else
			temp->above_med = false;
		temp = temp->next;
		i++;
	}
	return ;
}

int	stack_len(t_list *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_list	*find_biggest_value(t_list *stack)
{
	t_list	*biggest;

	if (stack == NULL)
		return (NULL);
	biggest = stack;
	while (stack->next)
	{
		if (stack->next->value > biggest->value)
			biggest = stack->next;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*find_smallest_value(t_list *stack)
{
	t_list	*smallest;

	if (stack == NULL)
		return (NULL);
	smallest = stack;
	while (stack->next)
	{
		if (stack->next->value < smallest->value)
			smallest = stack->next;
		stack = stack->next;
	}
	return (smallest);
}
