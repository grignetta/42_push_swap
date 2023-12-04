#include<stdio.h>
#include<stdlib.h>
#include "ft...h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    if (!begin_list || !f)
        return ;
    while(begin_list)
    {
        f(begin_list->data);
        begin_list=begin_list->next;
    }
}

void del(void *data)
{
    printf("%d\n", *(int *)data);
}

int main()
{
    t_list *list = malloc(sizeof(t_list));
    list->data = malloc(sizeof(int));
    *(int *)(list->data) = 1;
    list->next = malloc(sizeof(t_list));
    list->next->data = malloc(sizeof(int));
    *(int *)(list->next->data) = 2;
    list->next->next = NULL;

    t_list *temp;
    temp = list;

    while(list)
    {
        printf("%d\n", *(int *)list->data);
        list=list->next;
    }
    list = temp;

    ft_list_foreach(list, &del);
    /*while(list)
    {
        printf("%d\n", *(int *)list->data);
        list=list->next;
    }*/
}