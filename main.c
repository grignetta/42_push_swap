/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:27:28 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/05 19:38:45 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void print_stack(list *stack)
{
    list *temp = stack;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

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