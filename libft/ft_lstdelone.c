#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int *data;
    struct s_list *next;
}       t_list;

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
        return ;
    del(lst->data);
    free(lst);
}

void deleteInt(void *data)
{
    free(data);
}

int main()
{
    // Create a linked list node
    t_list *node = malloc(sizeof(t_list));
    node->data = malloc(sizeof(int));
    *(node->data) = 42;
    node->next = NULL;

    // Display the data before deletion
    printf("Before deletion: %d\n", *(node->data));

    // Test ft_lstdelone function
    ft_lstdelone(node, deleteInt);

    // Try to access the data after deletion (undefined behavior)
    printf("After deletion: %d\n", *(node->data)); // This line is commented out to avoid undefined behavior

    return 0;
}