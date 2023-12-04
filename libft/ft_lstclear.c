#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current;
    t_list *temp;

    if(!lst || !del)
        return ;
    current = *lst;
    while(current)
    {
        temp = current;
        current = current->next;
        del(temp->data);
        free(temp);
    }
    *lst = NULL;
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

    // Display the list before clearing
    printf("Before clearing:\n");
    t_list *current = list;
    while (current)
    {
        printf("%d\n", *(current->data));
        current = current->next;
    }

    // Test ft_lstclear function
    ft_lstclear(&list, free); // Assuming you want to use the standard free function to free the integer data

    // Display the list after clearing (should be empty)
    printf("After clearing:\n");
    current = list;
    while (current)
    {
        printf("%d\n", *(current->data));
        current = current->next;
    }

    return 0;
}