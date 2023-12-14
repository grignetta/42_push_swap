/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:29:52 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 18:48:21 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_a(t_list **a, t_list **b)
{
	t_list				*temp;
	t_list				*smaller_b;
	t_algorithm_params	params;

	temp = *a;
	if (temp == NULL)
		return ;
	while (temp)
	{
		set_current_position(a);
		set_current_position(b);
		smaller_b = find_smaller(temp, *b);
		if (!smaller_b)
			smaller_b = find_biggest_value(*b);
		temp->cost = return_smallest_cost((*a)->size, (*b)->size,
				temp->pos, smaller_b->pos);
		params.sizea = (*a)->size;
		params.sizeb = (*b)->size;
		params.abvmed_a = temp->above_med;
		params.abvmed_b = smaller_b->above_med;
		params.posa = temp->pos;
		params.posb = smaller_b->pos;
		temp->algorithm = return_algorithm(params, temp);
		temp = temp->next;
	}
}

void	set_cost_b(t_list **a, t_list **b)
{
	t_list				*temp;
	t_list				*bigger_a;
	t_algorithm_params	params;

	temp = *b;
	if (temp == NULL)
		return ;
	while (temp)
	{
		set_current_position(a);
		set_current_position(b);
		bigger_a = find_bigger(*a, temp);
		if (!bigger_a)
			bigger_a = find_smallest_value(*a);
		params.sizea = (*a)->size;
		params.sizeb = (*b)->size;
		params.abvmed_a = bigger_a->above_med;
		params.abvmed_b = temp->above_med;
		params.posa = bigger_a->pos;
		params.posb = temp->pos;
		temp->cost = return_smallest_cost((*a)->size, (*b)->size,
				bigger_a->pos, temp->pos);
		temp->algorithm = return_algorithm(params, temp);
		temp = temp->next;
	}
}

t_list	*find_smaller(t_list *a, t_list *b)
{
	t_list	*smaller;
	int		smallest_dif;

	smallest_dif = 0;
	smaller = NULL;
	while (b)
	{
		if (difference(a, b) > 0)
		{
			if (smallest_dif == 0)
			{
				smallest_dif = difference(a, b);
				smaller = b;
			}
			if (difference(a, b) < smallest_dif)
			{
				smallest_dif = difference(a, b);
				smaller = b;
			}
		}
		b = b->next;
	}
	return (smaller);
}

t_list	*find_bigger(t_list *a, t_list *b)
{
	t_list	*bigger;
	int		smallest_dif;

	smallest_dif = 0;
	bigger = NULL;
	while (a)
	{
		if (difference(a, b) > 0)
		{
			if (smallest_dif == 0)
			{
				smallest_dif = difference(a, b);
				bigger = a;
			}
			if (difference(a, b) < smallest_dif)
			{
				smallest_dif = difference(a, b);
				bigger = a;
			}
		}
		a = a->next;
	}
	return (bigger);
}

int	difference(t_list *a, t_list *b)
{
	int	dif;

	dif = a->value - b->value;
	return (dif);
}
