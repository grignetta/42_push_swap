/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:24:07 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/04 15:39:31 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

list *build_stack_main(list **stack, char **argv, int argc, bool *error)
{
    if (argc == 2)
        build_stack_string(stack, argv, error);
    else
        build_stack_args(stack, argv, argc, error);
    return(*stack);
}

list *build_stack_string(list **stack, char **argv, bool *error)
{
    char *token;
    long value;

    token = ft_strtok(argv[1], " ");
    while (token != NULL)
    {
        value = ft_atol(token, error);
        repeated_or_not_int(stack, value, error);
        if (!(*error))
            append_node(stack, (int)value);
        else
        {
            printf("Error\n"); //Change to my ft_printf!!!!!!!!!
            free_stack(stack);
            return(NULL);
        }
        token = ft_strtok(NULL, " ");
    }
    return (*stack);
}

list *build_stack_args(list **stack, char **argv, int argc, bool *error)
{
    int i = 0;

    long value;
    while (++i < argc)
    {
        value = ft_atol(argv[i], error);
        repeated_or_not_int(stack, value, error);
        if (!(*error))
            append_node(stack, (int)value);
        else
        {
            printf("Error\n"); //Change to my ft_printf!!!!!!!!!
            free_stack(stack);
            return(NULL);
        }
    }
    return (*stack);
}