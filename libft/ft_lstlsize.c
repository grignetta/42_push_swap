#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

int ft_lstsize(t_list *lst)
{
    int count = 0;
    while(lst)
    {
        count++;
        lst=lst->next;
    }
    return (count);
}

int main()
{
   t_list *newlist = malloc(sizeof(t_list));
   newlist->data = 1;
   newlist->next = malloc(sizeof(t_list));
   newlist->next->data = 2;
   newlist->next->next = NULL;

   int size = ft_lstsize(newlist);
   printf("%d", size);

}