#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst || !f)
        return ;
    while(lst)
    {
        f(lst->data);
        lst=lst->next;
    }
}

void printInt(void *data)
{
    printf("%d\n", *(int *)data);
}

int main()
{
    // Create a linked list
    t_list *list = malloc(sizeof(t_list));
    list->data = malloc(sizeof(int));
    *(list->data) = 1;
    list->next = malloc(sizeof(t_list));
    list->next->data = malloc(sizeof(int));
    *(list->next->data) = 2;
    list->next->next = NULL;

    // Test ft_lstiter function
    printf("Using ft_lstiter to print the list:\n");
    ft_lstiter(list, printInt);

    // Don't forget to free the allocated memory
    t_list *current = list;
    while (current)
    {
        t_list *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}