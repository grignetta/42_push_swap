/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:41:04 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/18 09:58:49 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				pos;
	bool			above_med;
	int				cost;
	int				size;
	struct s_node	*next;
	struct s_node	*prev;
	void			(*algorithm)(struct s_node **a, struct s_node **b,
			struct s_node *to_push, struct s_node *receive_pos);
}				t_list;

typedef struct s_algorithm_params
{
	int			sizea;
	int			sizeb;
	int			posa;
	int			posb;
	bool		abvmed_a;
	bool		abvmed_b;
	t_list		*to_push;
	t_list		*receive_pos;
}	t_algorithm_params;

//building a stack including error checking
t_list	*build_stack_args(t_list **stack, char **argv, int argc, bool *error);
t_list	*build_stack_string(t_list **stack, char **argv, bool *error);
t_list	*build_stack_main(t_list **stack, char **argv, int argc, bool *error);
long	ft_atol(const char *nptr, bool *error);
void	free_stack(t_list **stack);
void	repeated_or_not_int(t_list **stack, long value, bool *error);
void	append_node(t_list **stack, int nbr);

//sorting controls to stop unnecessary moving to stack b
bool	stack_sorted(t_list *stack);
bool	stack_half_sorted(t_list *stack);

//main sorting algorithm, all steps to do
void	sort_stack(t_list **a, t_list **b);
void	sort_three(t_list **stack);
void	handle_five(t_list **a, t_list **b);
void	finalize_sorting(t_list **stack);

//node moving from one to another stack
void	push_to_a(t_list **a, t_list **b);
void	push_to_b(t_list **a, t_list **b);
void	set_params(t_list **a, t_list **b, t_list *a_to_push,
			t_list *smaller_b);
t_list	*node_to_push(t_list **stack);
t_list	*find_smaller(t_list *a, t_list *b);
t_list	*find_bigger(t_list *a, t_list *b);
t_list	*find_biggest_value(t_list *stack);
t_list	*find_smallest_value(t_list *stack);

//finding the cost
void	set_cost_b(t_list **a, t_list **b);
void	set_cost_a(t_list **a, t_list **b);
int		return_smallest_cost(int sizea, int sizeb, int posa, int posb);
void	*return_algorithm(t_algorithm_params params, t_list *node);
void	set_current_position(t_list **stack);
void	set_len_pos(t_list *a, t_list *b);
int		difference(t_list *a, t_list *b);
int		stack_len(t_list *stack);

//cost calculation and the algorithm choice based on that
int		cost_rr(int posa, int posb);
int		cost_rrr(int posa, int posb, int sizea, int sizeb);
int		cost_ra_rrb(int posa, int posb, int sizeb);
int		cost_rra_rb(int posa, int posb, int sizea);
void	alg_rr(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos);
void	alg_rrr(t_list **a, t_list **b, t_list *to_push, t_list *receive_pos);
void	alg_ra_rrb(t_list **a, t_list **b, t_list *to_push,
			t_list *receive_pos);
void	alg_rra_rb(t_list **a, t_list **b, t_list *to_push,
			t_list *receive_pos);

//main commands for moving the numbers in a stack
void	push(t_list **dest, t_list **src);
void	pb(t_list **b, t_list **a);
void	pa(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
t_list	*ft_lstlast(t_list *lst);

//void 	print_stack(list *stack);
//void 	print_position(list *stack);
#endif
