/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:41:04 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/04 11:40:10 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct node
{
	int			value;
	int			pos;
	int			size;
	struct node	*next;
	struct node	*prev;
}				list;

long 	ft_atol(const char *nptr, bool *error);
void 	free_stack(list **stack);
list 	*build_stack(list **stack, char **argv, int argc, bool *error);
void	repeated_or_not_int(list **stack, long value,bool *error);
void	append_node(list **stack, int nbr);
list 	*ft_lstlast(list *lst);
void 	print_stack(list *stack); //delete later;
void	set_current_position(list **stack);
int		stack_len(list *stack);
bool 	stack_sorted(list *stack);
bool 	stack_half_sorted(list *stack);
void 	print_position(list *stack); //delete later;
list    *find_biggest_value(list *stack);
void    sort_three(list **stack);

void    set_len_pos(list *a,list  *b);//

bool 	stack_rev_sorted(list *stack);// probably not needed function
bool 	stack_half_rev_sorted(list *stack); // probably not needed function

void    finalize_sorting(list **stack);
void    push_to_b(list **a, list **b);
int 	difference(list *a, list *b);
list    *find_smaller(list *a, list *b);
list    *find_bigger(list *a, list *b);
void    push_to_a(list **a, list **b);
void    sort_stack(list **a, list **b);

void    push(list **dest, list **src);
void    pb(list **b, list **a);
void    pa(list **a, list **b);

void    rotate(list **stack);
void    ra(list **a);
void    rb(list **b);

void    rev_rotate(list **stack);
void    rra(list **a);
void    rrb(list **b);

void    swap(list **stack);
void    sa(list **a);
void    sb(list **b);

char	*ft_strtok(char *str, const char *delim); // better to pass through libft
char	*ft_strchr(const char *s, int c); // better to pass through libft

list *build_stack_args(list **stack, char **argv, int argc, bool *error);
list *build_stack_string(list **stack, char **argv, bool *error);
list *build_stack_main(list **stack, char **argv, int argc, bool *error);