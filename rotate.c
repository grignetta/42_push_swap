/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:08:30 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/02 20:48:15 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    rotate(list **stack)
{
    list    *last_node;
    list    *head_node;

    if (*stack == NULL)
        return ;
    if (stack_len(*stack) < 2)
        return;
    last_node = ft_lstlast(*stack);
    head_node = *stack;
    last_node->next = head_node;
    *stack = head_node->next;
    head_node->next->prev = NULL;
    head_node->prev = last_node;
    head_node->next = NULL;
}

void    ra(list **a)
{
    rotate(a);
        write(1, "ra\n", 3);
}

void    rb(list **b)
{
    rotate(b);
        write(1, "rb\n", 3);
}