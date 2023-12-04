#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

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

int main()
{
    t_list *list = malloc(sizeof(t_list));
    t_list **start = &list;
    list->data = 1;
    list->next = malloc(sizeof(t_list));
    list->next->data = 2;
    list->next->next = NULL;

    t_list *new = malloc(sizeof(t_list));
    new->data = 3;
    new->next = NULL;

    ft_lstadd_back(start, new);
    while(list)
    {
        printf("%d\n",list->data);
        list = list->next;
    }
}
