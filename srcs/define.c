/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:26:31 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/18 18:57:49 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_up(int key)
{
	return (key == XK_w || key == XK_W || key == XK_Up);
}

int	is_down(int key)
{
	return (key == XK_s || key == XK_S || key == XK_Down);
}

int	is_left(int key)
{
	return (key == XK_a || key == XK_A || key == XK_Left);
}

int	is_right(int key)
{
	return (key == XK_d || key == XK_D || key == XK_Right);
}

int	is_valid_char(int key)
{
	return (key == 'C' || key == 'E' || key == '0');
}
