/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:12:33 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/14 17:13:45 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_smallest_cost(int sizea, int sizeb, int posa, int posb)
{
	int	cost;
	int	temp;

	cost = cost_rr(posa, posb);
	temp = cost_rrr(posa, posb, sizea, sizeb);
	if (temp < cost)
		cost = temp;
	temp = cost_ra_rrb(posa, posb, sizeb);
	if (temp < cost)
		cost = temp;
	temp = cost_rra_rb(posa, posb, sizea);
	if (temp < cost)
		cost = temp;
	return (cost);
}

int	cost_rr(int posa, int posb)
{
	int	count;

	count = 0;
	while (posa != 1 && posb != 1)
	{
		posa--;
		posb--;
		count++;
	}
	while (posb != 1)
	{
		posb--;
		count++;
	}
	while (posa != 1)
	{
		posa--;
		count++;
	}
	return (count);
}

int	cost_rrr(int posa, int posb, int sizea, int sizeb)
{
	int	count;

	count = 0;
	while (posa != (sizea + 1) && posb != (sizeb + 1))
	{
		posa++;
		posb++;
		count++;
	}
	while (posb != (sizeb + 1))
	{
		posb++;
		count++;
	}
	while (posa != (sizea + 1))
	{
		posa++;
		count++;
	}
	return (count);
}

int	cost_ra_rrb(int posa, int posb, int sizeb)
{
	int	count;

	count = 0;
	while (posa != 1)
	{
		posa--;
		count++;
	}
	while (posb != (sizeb + 1))
	{
		posb++;
		count++;
	}
	return (count);
}

int	cost_rra_rb(int posa, int posb, int sizea)
{
	int	count;

	count = 0;
	while (posa != (sizea + 1))
	{
		posa++;
		count++;
	}
	while (posb != 1)
	{
		posb--;
		count++;
	}
	return (count);
}
