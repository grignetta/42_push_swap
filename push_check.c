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

void    push(list **dest, list **src)
{
    list    *node_to_push;

    if (*src == NULL)
        return ;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (*dest == NULL)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        node_to_push->next->prev = node_to_push;
        *dest = node_to_push;
    }
}

void    pb(list **b, list **a)
{
    push(b, a);
        write(1, "pa\n", 3);
}

void    pa(list **a, list **b)
{
    push(a, b);
        write(1, "pa\n", 3);
}

int main() {
    list *stackA = NULL;
    list *stackB = NULL;

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

    // Inside main function
    printf("Initial state:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("Stack B: ");
    printStack(stackB);
    printf("\n");

    // Perform a push from B to A
    pb(&stackB, &stackA);
    pb(&stackB, &stackA);
    pb(&stackB, &stackA);

    // After pa or pb operation
    printf("State after pa:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("Stack B: ");
    printStack(stackB);
    printf("\n");
    return 0;
}