#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
    void    *content;
    struct s_list *next;
}   t_list;

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}

int main()
{
    t_list *newlst = malloc(sizeof(t_list));
    newlst->content = 1;
    newlst->next = malloc (sizeof(t_list));
    newlst->next->content = 2;
    newlst->next->next = NULL;
    t_list **pointlist = &newlst;
    t_list *new = malloc(sizeof(t_list));
    new->content = 0;
    t_list *head = newlst;
    while(newlst)
    {
        printf ("%d\n", newlst->content);
        newlst=newlst->next;
    }
    printf ("\n");
    newlst = head;
    ft_lstadd_front (pointlist, new);
    while(newlst)
    {
        printf ("%d\n", newlst->content);
        newlst=newlst->next;
    }

}