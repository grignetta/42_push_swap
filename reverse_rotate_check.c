#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void    rev_rotate(list **stack)
{
    list    *last_node;
    list    *head_node;

    if (*stack == NULL)
        return ;
    if (stack_len(*stack) < 2)
        return;
    last_node = ft_lstlast(*stack);
    head_node = *stack;
    last_node->next = head_node;
    *stack = head_node->next;
    head_node->next->prev = NULL;
    head_node->prev = last_node;
    head_node->next = NULL;
}

void    rra(list **a)
{
    rev_rotate(a);
        write(1, "rra\n", 4);
}

void    rrb(list **b)
{
    rev_rotate(b);
        write(1, "rrb\n", 4);
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

    rra(&stackA);

    printf("State after pa:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("\n");
    return 0;
}