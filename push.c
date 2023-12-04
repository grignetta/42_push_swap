/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:05:34 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/04 13:53:54 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    push(list **dest, list **src)
{
    list    *node_to_push;

    if (*src == NULL)
        return ;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (*dest == NULL)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        node_to_push->next->prev = node_to_push;
        *dest = node_to_push;
    }
    return ;
}

void    pb(list **b, list **a)
{
    push(b, a);
        write(1, "pb\n", 3);
    return ;
}

void    pa(list **a, list **b)
{
    push(a, b);
        write(1, "pa\n", 3);
    return ;
}