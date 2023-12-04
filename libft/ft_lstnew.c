#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
    void    *content;
    struct s_list *next;
}   t_list;


t_list *ft_lstnew(void *content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (node == NULL)
        return(NULL);
    node->content = content;
    node->next = NULL;
    return(node);
}

int main()
{
    int *content = malloc(sizeof(int));
    *content = 42;

    t_list *newlist = ft_lstnew(content);
    if (newlist != NULL)
    {
        printf("Content: %d\n", *((int *)newlist->content));
        free(content);
        free(newlist);
    }
    else
        printf("Error\n");
    return 0;
    
}