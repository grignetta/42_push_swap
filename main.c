/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:27:28 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 18:24:34 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	bool	error;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	error = false;
	if (argc > 1)
	{
		build_stack_main(&a, argv, argc, &error);
		if (a && !stack_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else
				sort_stack(&a, &b);
		}
		else if (error)
			return (free_stack(&a), 1);
		return (free_stack(&a), 0);
	}
	else
		return (1);
}
/*
void print_stack(t_list *stack)
{
	t_list *temp = stack;
	while(temp != NULL) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void print_position(t_list *stack)
{
	t_list *temp = stack;
	while(temp != NULL) {
		printf("%d ", temp->pos);
		temp = temp->next;
	}
	printf("\n");
}
*/
