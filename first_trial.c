#include"push_swap.h"

list *ft_lstlast(list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next != NULL)
        lst=lst->next;
    return(lst);
}

void	set_current_position(list **stack)
{
	int	i;
    list *temp;

    temp = *stack;
	i = 1;
	if (temp == NULL)
		return ;
	while (temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
    return ;
}

int	stack_len(list *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

bool stack_sorted(list *stack)
{

    while (stack && stack->next)
    {
        if (stack->value < stack->next->value)
            stack = stack->next;
        else
            return (false);
    }
    return (true);
}

bool stack_half_sorted(list *stack)
{
    list *temp;

    temp = stack;
    while (temp->next && temp->value < temp->next->value)
        temp = temp->next;
    if (temp->next)
        temp = temp->next;
    while (temp->next)
    {
        if (temp->value < temp->next->value && temp->value < stack->value)
            temp = temp->next;
        else
            return (false);
    }
    if (temp->value > stack->value)
        return(false);
    return (true);
}

void print_position(list *stack)
{
    list *temp = stack;
    while(temp != NULL) {
        printf("%d ", temp->pos);
        temp = temp->next;
    }
    printf("\n");
}

list    *find_biggest_value(list *stack)
{
    list    *biggest;

    if (stack == NULL)
        return (NULL);
    biggest = stack;
    while(stack->next)
    {
        if(stack->next->value > biggest->value)
            biggest = stack->next;
        stack = stack->next;
    }
    return (biggest);
}

list    *find_smallest_value(list *stack)
{
    list    *smallest;

    if (stack == NULL)
        return (NULL);
    smallest = stack;
    while(stack->next)
    {
        if(stack->next->value < smallest->value)
            smallest = stack->next;
        stack = stack->next;
    }
    return (smallest);
}

void sort_three(list **stack)
{
    list *biggest_node;

    biggest_node = find_biggest_value(*stack);
    if (*stack == biggest_node)
        ra(stack);
    else if ((*stack)->next == biggest_node)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
    return ;
}

void    set_len_pos(list *a,list  *b)
{
    if (a)
    {
        set_current_position(&a);
        a->size = stack_len(a);
        //set_cost_a(&a, &b);
    }
    if (b)
    {
        set_current_position(&b);
        b->size = stack_len(b);
        //set_cost_b(&a, &b);
    }
    return ;
}

int cost_rr(int posa, int posb)
{
    int count;

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

int cost_rrr(int posa, int posb, int sizea, int sizeb)
{
    int count;

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

int cost_ra_rrb(int posa, int posb, int sizeb)
{
    int count;

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

int cost_rra_rb(int posa, int posb, int sizea)
{
    int count;

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

bool stack_rev_sorted(list *stack)// probably not needed function
{

    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            stack = stack->next;
        else
            return (false);
    }
    return (true);
}

bool stack_half_rev_sorted(list *stack) // probably not needed function
{
    int flag;

    flag = 0;
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            stack = stack->next;
        else if (stack->next->next != NULL && stack->next->value > stack->next->next->value)
        {
            flag = 1;
            stack = stack->next;
            while(stack && stack->next)
            {
                if (stack->value > stack->next->value)
                    stack = stack->next;
                else
                    return (false);
            }
        }
        else
            return (false);
    }
    if (flag == 1)
        return (true);
    return (false);
}

void    finalize_sorting(list **stack)
{
    list    *biggest;
    int     pos_to_last;

    (*stack)->size = stack_len(*stack);
    biggest = find_biggest_value(*stack);
    pos_to_last = (*stack)->size - biggest->pos + 1;
    //set_current_position(stack);
    while (*stack)
    {
        if (stack_half_sorted(*stack))
        {
            if (biggest->pos <= pos_to_last)
                ra(stack);
            else
                rra(stack);
        }
        if (stack_sorted(*stack))
            break;
    }
    return ;
}

void    sort_stack(list **a, list **b)
{
    //set_len_pos(*a, *b);
    (*a)->size = stack_len(*a);
    while ((*a)->size > 3)
    {
        if (stack_sorted(*a))
            break;
        if (stack_half_sorted(*a))
            break;
        push_to_b(a, b);
        //print_stack(*a);
        //print_stack(*b);
        set_len_pos(*a, *b);
        set_cost_a(a, b);
    }
    if ((*a)->size > 3)
        finalize_sorting(a);
    else
    {
        sort_three(a);
        //print_stack(*a);
    }
    while (*b)
    {
        push_to_a(a, b);
        //print_stack(*a);
        //print_stack(*b);
        //set_cost_b(a, b);
    }
    finalize_sorting(a);
    //print_stack(*a);
    return ;
}

void    push_to_a(list **a, list **b)
{
    list    *b_to_push;
    list    *bigger_a;
    algorithm_params params;

    set_len_pos(*a, *b);
    set_cost_b(a, b);
    b_to_push = node_to_push(b);//edited
    bigger_a = find_bigger(*a, b_to_push);
        if (!bigger_a)
            bigger_a = find_smallest_value(*a);
    params.sizea = (*a)->size;
    params.sizeb = (*b)->size;
    params.posb = b_to_push->pos;
    params.posa = bigger_a->pos;
    params.to_push = bigger_a;
    params.receive_pos = b_to_push;
    b_to_push->algorithm(a, b, params.to_push, params.receive_pos);//edited
    return (pa(a, b));
}
/*
void    push_to_b(list **a, list **b)
{
    list    *smaller_b;
    int     pos_to_last;

    if (!*b)
        return (pb(b, a));
    if ((*b)->next == NULL)
    {
        if ((*a)->value < (*b)->value)
            return (pb(b,a),sb(b));
        return (pb(b, a));
    }
    set_len_pos(*a, *b);
    smaller_b = find_smaller(*a, *b);
    if (!smaller_b)
        smaller_b = find_biggest_value(*b);
    pos_to_last = (*b)->size - smaller_b->pos + 1;
    while (smaller_b->pos != 1)
    {
        if (smaller_b->pos <= pos_to_last)
            rb(b);
        else
            rrb(b);
        set_len_pos(*b, *a);
    }
    return (pb(b, a));
}
*/

void    push_to_b(list **a, list **b)
{
    list    *a_to_push;
    list    *smaller_b;
    algorithm_params params;

    if (!*b)
        return (pb(b, a));
    if ((*b)->next == NULL)
    {
        if ((*a)->value < (*b)->value)
            return (pb(b,a),sb(b));
        return (pb(b, a));
    }
    set_len_pos(*a, *b);
    set_cost_a(a, b);
    a_to_push = node_to_push(a);//edited
    smaller_b = find_smaller(a_to_push, *b);
        if (!smaller_b)
            smaller_b = find_biggest_value(*b);
    params.sizea = (*a)->size;
    params.sizeb = (*b)->size;
    params.posa = a_to_push->pos;
    params.posb = smaller_b->pos;
    params.to_push = a_to_push;
    params.receive_pos = smaller_b;
    a_to_push->algorithm(a, b, params.to_push, params.receive_pos);//edited
    return (pb(b, a));
}
void    alg_rr(list **a, list **b, list *to_push, list *receive_pos)
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

void    alg_rrr(list **a, list **b, list *to_push, list *receive_pos)
{
    set_len_pos(*a, *b);
    while (to_push->pos != (*a)->size && receive_pos->pos != (*b)-> size)
    {
        rrr(a,b);
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
void    alg_ra_rrb(list **a, list **b, list *to_push, list *receive_pos)
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
        //printf("position b:%d\n", receive_pos->pos);
        //printf("size b:%d\n", (*b)->size);
        //print_stack(*b);
    }
    rrb(b);
    return ;
}

void    alg_rra_rb(list **a, list **b, list *to_push, list *receive_pos)
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

list    *node_to_push(list **stack)
{
    list    *to_push;

    if (stack == NULL)
        return (NULL);
    to_push = *stack;
    while((*stack)->next)
    {
        if(to_push->next->cost < to_push->cost)
            to_push = (*stack)->next;
        stack = &(*stack)->next;
    }
    return (to_push);
}

void set_cost_a(list **a,list  **b)
{
    list                *temp;
    list                *smaller_b;
    algorithm_params    params;

    temp = *a;
    if (temp == NULL)
        return;
    while (temp)
    {
        set_current_position(a);
        set_current_position(b);
        smaller_b = find_smaller(temp, *b);
        if (!smaller_b)
            smaller_b = find_biggest_value(*b);
        temp->cost = return_smallest_cost((*a)->size ,(*b)->size, temp->pos, smaller_b->pos);
        // Create a variable of type algorithm_params and set its fields
        params.sizea = (*a)->size;
        params.sizeb = (*b)->size;
        params.posa = temp->pos;
        params.posb = smaller_b->pos;
        // Pass the params variable to return_algorithm
        temp->algorithm = return_algorithm(params, temp);
        temp = temp->next;
    }
}

void *return_algorithm(algorithm_params params, list *node)
{
    int cost;

    cost = cost_rra_rb(params.posa, params.posb, params.sizea);
    if (cost == node->cost)
        node->algorithm = alg_rra_rb;
    cost = cost_ra_rrb(params.posa, params.posb, params.sizeb);
    if (cost == node->cost)
        node->algorithm = alg_ra_rrb;
    cost = cost_rrr(params.posa, params.posb, params.sizea, params.sizeb);
    if (cost == node->cost)
        node->algorithm = alg_rrr;
    cost = cost_rr(params.posa, params.posb);
    if (cost == node->cost)
        node->algorithm = alg_rr;
    return (node->algorithm);
}
/*
void *return_algorithm(int sizea, int sizeb, int posa, int posb);
{
    int cost;
    int temp;

    void *algorithm;
    cost = cost_rr(posa, posb, sizea, sizeb);
    algorithm = (*f)alg_rr(list **a, list **b);
    temp = cost_rrr(posa, posb, sizea, sizeb);
    if (temp < cost)
    {
        cost = temp;
        algorithm = (*f)alg_rrr(list **a, list **b);
    }
    temp = cost_ra_rrb(posa, posb, sizea, sizeb);
    if (temp < cost)
    {
        cost = temp;
        algorithm = (*f)alg_ra_rrb(list **a, list **b);
    }
    temp = cost_rra_rb(posa, posb, sizea, sizeb);
    if (temp < cost)
    {
        cost = temp;
        algorithm = (*f)alg_rra_rb(list **a, list **b);
    }
    return (algorithm);
}
*/

int return_smallest_cost(int sizea, int sizeb, int posa, int posb)
{
    int cost;
    int temp;

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

int difference(list *a, list *b)
{
    int dif;

    dif = a->value - b->value;
    return (dif);
}

list    *find_smaller(list *a, list *b)
{
    list    *smaller;
    int     smallest_dif;
    smallest_dif = 0;

    smaller = NULL;
    while(b)
    {
        if (difference(a,b) > 0)
        {
            if (smallest_dif == 0)
            {
                smallest_dif = difference(a,b);
                smaller = b;
            }
            if (difference(a,b) < smallest_dif)
            {
                smallest_dif = difference(a,b);
                smaller = b;
            }
        }
        b = b->next;
    }
    return (smaller);
}

list    *find_bigger(list *a, list *b)
{
    list    *bigger;
    int     smallest_dif;
    smallest_dif = 0;

    bigger = NULL;
    while(a)
    {
        if (difference(a,b) > 0)
        {
            if (smallest_dif == 0)
            {
                smallest_dif = difference(a,b);
                bigger = a;
            }
            if (difference(a,b) < smallest_dif)
            {
                smallest_dif = difference(a,b);
                bigger = a;
            }
        }
        a = a->next;
    }
    return (bigger);
}
/*
void    push_to_a(list **a,list **b)
{
    list    *big_a;
    int     pos_to_last;
    int     flag_no_big;

    flag_no_big = 0;
    set_len_pos(*a, *b);
    big_a = find_bigger(*a, *b);
    if (!big_a )
    {
        big_a = find_biggest_value(*a);
        flag_no_big = 1;
    }
    pos_to_last = (*a)->size - big_a->pos + 1;
    while (big_a->pos != 1)
    {
        if (big_a->pos == (*a)->size && flag_no_big == 1)
            break;
        if (big_a->pos <= pos_to_last)
            ra(a);
        else
            rra(a);
        set_len_pos(*a, *b);
    }
    pa(a, b);
    return ;
}
*/
/*
void    push_to_a(list **a, list **b)
{
    list    *b_to_push;

    set_len_pos(*a, *b);
    set_cost_b(a, b);
    b_to_push = node_to_push(b);
    b_to_push->algorithm(a, b, params.to_push, params.receive_pos);
    return (pa(a, b));
}
*/


void set_cost_b(list **a,list  **b)
{
    list                *temp;
    list                *bigger_a;
    algorithm_params    params;

    temp = *b;
    if (temp == NULL)
        return;
    while (temp)
    {
        set_current_position(a);
        set_current_position(b);
        bigger_a = find_bigger(*a, temp);
        if (!bigger_a)
            bigger_a = find_smallest_value(*a);
        //temp->cost = return_smallest_cost((*a)->size ,(*b)->size, temp->pos, bigger_a->pos);
        temp->cost = return_smallest_cost((*a)->size , (*b)->size, bigger_a->pos, temp->pos);
        // Create a variable of type algorithm_params and set its fields
        params.sizea = (*a)->size;
        params.sizeb = (*b)->size;
        params.posa = bigger_a->pos;
        params.posb = temp->pos;
        // Pass the params variable to return_algorithm
        temp->algorithm = return_algorithm(params, temp);
        temp = temp->next;
    }
}