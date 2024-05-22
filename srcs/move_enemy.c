/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:23:00 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 17:57:38 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_left_rigth(t_data *game, int random)
{
	t_enemy enemy;
	enemy = game->enemy;
	if(game->map[enemy.x][enemy.y + random] == '0')
	
}