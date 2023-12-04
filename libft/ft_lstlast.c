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

int main()
{
    /*
    t_list *newlst = malloc(sizeof(t_list));
    *(newlst->data) = 1;
    newlst->next = malloc(sizeof(t_list));
    *(newlst->next->data) = 2;
    newlst->next->next = malloc(sizeof(t_list));
    *(newlst->next->next->data) = 3;
    newlst->next->next->next = NULL;
    t_list *lastint = ft_lstlast(newlst);
    printf("%d", *(lastint->data));
    */

    t_list *newlst = malloc(sizeof(t_list));
    newlst->data = malloc(sizeof(int)); // Allocate memory for the integer
    *(newlst->data) = 1; // Assign the value 1
    newlst->next = malloc(sizeof(t_list));
    newlst->next->data = malloc(sizeof(int)); // Allocate memory for the integer
    *(newlst->next->data) = 2; // Assign the value 2
    newlst->next->next = malloc(sizeof(t_list));
    newlst->next->next->data = malloc(sizeof(int)); // Allocate memory for the integer
    *(newlst->next->next->data) = 3; // Assign the value 3
    newlst->next->next->next = NULL;
    t_list *lastint = ft_lstlast(newlst);
    printf("%d", *(lastint->data));
}