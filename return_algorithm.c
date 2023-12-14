/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:22:50 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 18:35:48 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*return_algorithm(t_algorithm_params prms, t_list *node)
{
	int	cost;

	cost = cost_rr(prms.posa, prms.posb);
	if (cost == node->cost && prms.abvmed_a == true && prms.abvmed_b == true)
	{
		node->algorithm = alg_rr;
		return (node->algorithm);
	}
	cost = cost_rrr(prms.posa, prms.posb, prms.sizea, prms.sizeb);
	if (cost == node->cost && prms.abvmed_a == false && prms.abvmed_b == false)
	{
		node->algorithm = alg_rrr;
		return (node->algorithm);
	}
	cost = cost_ra_rrb(prms.posa, prms.posb, prms.sizeb);
	if (cost == node->cost && prms.abvmed_a == true && prms.abvmed_b == false)
	{
		node->algorithm = alg_ra_rrb;
		return (node->algorithm);
	}
	cost = cost_rra_rb(prms.posa, prms.posb, prms.sizea);
	if (cost == node->cost && prms.abvmed_a == false && prms.abvmed_b == true)
		node->algorithm = alg_rra_rb;
	return (node->algorithm);
}

void	alg_rr(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos)
{
	set_len_pos(*a, *b);
	while (to_push->pos != 1 && receive_pos->pos != 1)
	{
		rr(a, b);
		set_len_pos(*a, *b);
	}
	while (to_push->pos != 1)
	{
		ra(a);
		set_len_pos(*a, *b);
	}
	while (receive_pos->pos != 1)
	{
		rb(b);
		set_len_pos(*a, *b);
	}
	return ;
}

void	alg_rrr(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos)
{
	set_len_pos(*a, *b);
	while (to_push->pos != (*a)->size && receive_pos->pos != (*b)-> size)
	{
		rrr(a, b);
		set_len_pos(*a, *b);
	}
	while (to_push->pos != (*a)->size)
	{
		rra(a);
		set_len_pos(*a, *b);
	}
	while (receive_pos->pos != (*b)->size)
	{
		rrb(b);
		set_len_pos(*a, *b);
	}
	rra(a);
	rrb(b);
	return ;
}

void	alg_ra_rrb(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos)
{
	set_len_pos(*a, *b);
	while (to_push->pos != 1)
	{
		ra(a);
		set_len_pos(*a, *b);
	}
	while (receive_pos->pos != (*b)->size)
	{
		rrb(b);
		set_len_pos(*a, *b);
	}
	rrb(b);
	return ;
}

void	alg_rra_rb(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos)
{
	set_len_pos(*a, *b);
	while (receive_pos->pos != 1)
	{
		rb(b);
		set_len_pos(*a, *b);
	}
	while (to_push->pos != (*a)->size)
	{
		rra(a);
		set_len_pos(*a, *b);
	}
	rra(a);
	return ;
}
