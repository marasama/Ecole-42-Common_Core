/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:31:36 by adurusoy          #+#    #+#             */
/*   Updated: 2023/01/26 17:31:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_pf_string(char *a, int *c)
{
    int     b;

    b = 0;
    while (a[b])
    {
        ft_putchar(a[b], *c)
        b++;
    }
}