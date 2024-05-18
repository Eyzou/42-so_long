/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:32:10 by elo               #+#    #+#             */
/*   Updated: 2024/05/18 10:33:33 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int    ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (to_find[0] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] == to_find[j])
        {
            while (str[i + j] == to_find[j] && to_find[j])
                j++;
            if (to_find[j] == '\0')
                return (1);
        }
        i++;
    }
    return (0);
}