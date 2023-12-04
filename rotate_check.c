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

void    rotate(list **stack)
{
    list    *last_node;
	list	*head_node;

    if (*stack == NULL)
        return ;
	if (stack_len(*stack) < 2)
		return;
    last_node = ft_lstlast(*stack);
    head_node = *stack;
    last_node->next = head_node;
    last_node->prev->next = NULL;
    head_node->prev = last_node;
    last_node->prev = NULL;
    *stack = last_node;
}

void    ra(list **a)
{
    rotate(a);
        write(1, "ra\n", 3);
}

void    rb(list **b)
{
    rotate(b);
        write(1, "rb\n", 3);
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

    ra(&stackA);

    printf("State after pa:\n");
    printf("Stack A: ");
    printStack(stackA);
    printf("\n");
    return 0;
}