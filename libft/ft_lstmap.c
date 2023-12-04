#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

t_list *ft_lstnew(void *content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (node == NULL)
        return(NULL);
    node->data = content;
    node->next = NULL;
    return(node);
}

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

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next != NULL)
        lst=lst->next;
    return(lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    if (lst == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last->next = new;
    new->next = NULL;//Needed?
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_node;

    if (!lst)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        if (f)
            new_node = ft_lstnew(f(lst->data));
        else
            new_node = ft_lstnew(lst->data);
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }
    return new_list;
}

// Function to transform an integer (you can replace it with your own custom function)
void *transformInt(void *data)
{
    int *result = malloc(sizeof(int));
    if (!result)
        return NULL;
    *result = *(int *)data * 2; // Example: doubling the integer
    return result;
}

// Function to print an integer (you can replace it with your own custom function)
void printInt(void *data)
{
    printf("%d\n", *(int *)data);
}

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

    // Print the original list
    printf("Original list:\n");
    ft_lstiter(list, printInt);

    // Use ft_lstmap to create a new list with transformed content
    t_list *new_list = ft_lstmap(list, transformInt, free);

    // Print the new list
    printf("New list (transformed content):\n");
    ft_lstiter(new_list, printInt);

    // Free the memory of both lists
    ft_lstclear(&list, free);
    ft_lstclear(&new_list, free);

    return 0;
}