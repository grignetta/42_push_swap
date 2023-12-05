/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prebuild_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:32:43 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/04 15:33:09 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

long ft_atol(const char *nptr, bool *error)
{
    int i;
    int count;
    long number;

    *error = true;
    i = 0;
    count = 0;
    number = 0;
    while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i++] == '-')
            count = 1;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        number = number * 10 + (nptr[i++] - '0');
        *error = false;
    }
    if(nptr[i] != '\0')
        *error = true;
    if ((count % 2) == 1)
        return (-1 * number);
    return (number);
}

void free_stack(list **stack)
{
	list *temp;
	list *current;

	if (stack == NULL)
		return;
	current = *stack;
	while (current)
	{
        temp = current;
        current = current->next;
		free(temp);
	}
	*stack = NULL;
    return ;
}

void repeated_or_not_int(list **stack, long value, bool *error)
{
    list *temp;

    temp = *stack;
    if (*error)
    {
        return;
    }
    if (value > INT_MAX || value < INT_MIN)
    {
        *error = true;
        return ;
    }
	while(temp)
	{
		if(temp->value == value)
		{
			*error = true;
			return ;
		}
		temp = temp->next;
	}
	*error = false;
	return ;
}

void	append_node(list **stack, int nbr)
{
	list	*node;
	list	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(list));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
    return ;
}