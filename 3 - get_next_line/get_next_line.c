/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:39:53 by adurusoy          #+#    #+#             */
/*   Updated: 2023/03/15 17:39:53 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>

char *get_next_line(int fd)
{
    static int  a;
    char    *c;
    int     b;

    a = 1;
    while (b != 0)
    {
        c = malloc(sizeof(char) * a + 1);
        c[a + 1] = '\0';
        b = read(fd, c, a);
        if (c[a] == '\n')
            return (c);
        free(c);
        a++;
    }
    return(NULL);
}