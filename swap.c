/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:11:20 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 18:24:34 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	if (second_node->next != NULL)
		second_node->next->prev = first_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	second_node->prev = NULL;
	first_node->prev = second_node;
	*stack = second_node;
	return ;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
	return ;
}
