#include"push_swap.h"
#include <unistd.h>

typedef struct list {
    int value;
    struct list *prev;
    struct list *next;
} list;

void printStack(list *stack) {
    while (stack != NULL) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int    stack_len(list *stack)
{
    int    count;

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

list *ft_lstlast(list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next != NULL)
        lst=lst->next;
    return(lst);
}
/*
void    swap(list **stack)
{
    list    *last_node;
    list    *penultimo;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    last_node = ft_lstlast(*stack);
	penultimo = last_node->prev;
	if (penultimo->prev != NULL)
		penultimo->prev->next = last_node;
	last_node->prev = penultimo->prev;
	penultimo->prev = last_node;
	penultimo->next = NULL;
	last_node->next = penultimo;
}
*/

void    swap(list **stack)
{
    list    *first_node;
    list    *second_node;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    first_node = *stack;
	second_node = (*stack)->next;
	if (second_node->next != NULL)
		second_node->next->prev = first_node; 
	first_node->next = second_node->next;
	second_node->next = first_node;
	second_node->next = NULL;
	first_node->prev = second_node;
    *stack = second_node;
}

void    sa(list **a)
{
    swap(a);
        write(1, "rra\n", 3);
}

void    sb(list **b)
{
    swap(b);
        write(1, "rrb\n", 3);
}

int main() {
    list *stackA = NULL;

     for (int i = 5; i >= 1; --i)
     {
        list *newNode = malloc(sizeof(list));
        newNode->value = i;
        newNode->prev = NULL;
        newNode->next = stackA;
        if (stackA != NULL) {
            stackA->prev = newNode;
        }
        stackA = newNode;
    }

    printf("Initial state:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("\n");

    sa(&stackA);

    printf("State after pa:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("\n");
    return 0;
}
