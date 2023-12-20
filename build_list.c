/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:24:07 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/20 12:03:17 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list	*build_stack_main(t_list **stack, char **argv, int argc, bool *error)
{
	if (argc == 2)
		build_stack_string(stack, argv, error);
	else
		build_stack_args(stack, argv, argc, error);
	return (*stack);
}

t_list	*build_stack_string(t_list **stack, char **argv, bool *error)
{
	char	*token;
	long	value;

	token = ft_strtok(argv[1], " ");
	while (token != NULL)
	{
		value = ft_atol(token, error);
		repeated_or_not_int(stack, value, error);
		if (!(*error))
		{
			append_node(stack, (int)value);
			if (!*stack)
				return (NULL);
		}
		else
		{
			write(2, "Error\n", 6);
			free_stack(stack);
			return (NULL);
		}
		token = ft_strtok(NULL, " ");
	}
	return (*stack);
}

t_list	*build_stack_args(t_list **stack, char **argv, int argc, bool *error)
{
	int		i;
	long	value;

	i = 0;
	while (++i < argc)
	{
		value = ft_atol(argv[i], error);
		repeated_or_not_int(stack, value, error);
		if (!(*error))
			append_node(stack, (int)value);
		else
		{
			write(2, "Error\n", 6);
			free_stack(stack);
			return (NULL);
		}
	}
	return (*stack);
}
