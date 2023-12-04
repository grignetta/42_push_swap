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

list *ft_lstlast(list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next != NULL)
        lst=lst->next;
    return(lst);
}

void print_stack(list *stack)
{
    list *temp = stack;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
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
    set_current_position(&a);
    a->size = stack_len(a);
    if (b)
    {
        set_current_position(&b);
        b->size = stack_len(b);
    }
    return ;
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
    set_len_pos(*a, *b);
    while ((*a)->size > 3)
    {
        if (stack_sorted(*a))
            break;
        if (stack_half_sorted(*a))
            break;
        push_to_b(a, b);
        set_len_pos(*a, *b);
    }
    if ((*a)->size > 3)
        finalize_sorting(a);
    else
        sort_three(a);
    while (*b)
        push_to_a(a, b);
    finalize_sorting(a);
    return ;
}

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


/*
int main(int argc, char **argv)
{
	bool error = false;
	int i = 0;
	list *a = NULL;
    list *b = NULL;

    for (int i = 1; i <= 5; ++i)
    {
        list *newNode = malloc(sizeof(list));
        newNode->value = i*i;
        newNode->prev = NULL;
        newNode->next = b;
        if (b != NULL)
        {
            b->prev = newNode;
        }
        b = newNode;
    }
    print_stack(b);

    //list *smaller = NULL;
    list *biggest = NULL;
	if (argc > 1)
		build_stack(&a, argv, argc, &error);
	if (error)
		return(1);
    set_current_position(&a);
    print_stack(a);
    printf("%d\n", stack_len(a));
    print_position(a);
    printf("%s\n", stack_sorted(a)?"true":"false");
    printf("%s\n", stack_half_sorted(a)?"true":"false");
    biggest = find_biggest_value(a);
    //sort_three(&a);
    sort_stack(&a, &b);
    print_stack(a);
    //smaller = find_smaller(a, b);
    //printf("%d\n", smaller->value);
    //push_to_b(&a, &b);
    //finalize_sorting(&a);
	return(0);
}
*/

int main(int argc, char **argv)
{
    bool error;
    list *a;
    list *b;

    a = NULL;
    b = NULL;
    error = false;
    if (argc > 1)
    {
        build_stack_main(&a, argv, argc, &error);
        if (a && !stack_sorted(a))
        {
            if(stack_len(a) == 2)
                sa(&a);
            else if(stack_len(a) == 3)
                sort_three(&a);
            else
                sort_stack(&a, &b);
        }
        else if (error)
            return(free_stack(&a), 1);
        return(free_stack(&a), 0);
    }
    else
        return(1);
    return(free_stack(&a), 0);
}

list *build_stack_main(list **stack, char **argv, int argc, bool *error)
{
    if (argc == 2)
        build_stack_string(stack, argv, error);
    else
        build_stack_args(stack, argv, argc, error);
    return(*stack);
}

list *build_stack_string(list **stack, char **argv, bool *error)
{
    char *token;
    long value;

    token = ft_strtok(argv[1], " ");
    while (token != NULL)
    {
        value = ft_atol(token, error);
        repeated_or_not_int(stack, value, error);
        if (!(*error))
            append_node(stack, (int)value);
        else
        {
            printf("Error\n"); //Change to my ft_printf!!!!!!!!!
            free_stack(stack);
            return(NULL);
        }
        token = ft_strtok(NULL, " ");
    }
    return (*stack);
}

list *build_stack_args(list **stack, char **argv, int argc, bool *error)
{
    int i = 0;

    long value;
    while (++i < argc)
    {
        value = ft_atol(argv[i], error);
        repeated_or_not_int(stack, value, error);
        if (!(*error))
            append_node(stack, (int)value);
        else
        {
            printf("Error\n"); //Change to my ft_printf!!!!!!!!!
            free_stack(stack);
            return(NULL);
        }
    }
    return (*stack);
}

list *build_stack(list **stack, char **argv, int argc, bool *error)
{
    int i = 0;

    long value;
    while (++i < argc)
    {
        value = ft_atol(argv[i], error);
        repeated_or_not_int(stack, value, error);
        if (!(*error))
            append_node(stack, (int)value);
        else
        {
            printf("Error\n"); //Change to my ft_printf!!!!!!!!!
            free_stack(stack);
            return(NULL);
        }
    }
    return (*stack);
}