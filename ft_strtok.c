/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:57:17 by dpadenko          #+#    #+#             */
/*   Updated: 2023/12/03 17:55:00 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include"push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = (unsigned char) c;
	while (*s != '\0')
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (!i && *s == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*i;
	char		*result;

	result = str;
	if (str)
		i = str;
	while(*i && ft_strchr(delim, *i))
		i++;
	str = i;
	while(*str)
	{
		result = str;
		while (str && !ft_strchr(delim, *str))
			str++;
		if(*str)
			i = str + 1;
		else
			i = str;
		*str = '\0';
	}
		return (result);
}
/*
int main(void)
{
    char str[] = "Hello,World!This,is,a,test";
    const char delim[] = ",!";

    char *token = ft_strtok(str, delim);

    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = ft_strtok(NULL, delim);
    }
    return 0;
}
*/