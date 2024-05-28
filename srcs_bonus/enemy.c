/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:23:00 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/28 10:45:56 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"
#include <time.h>

static int	move_enemy_up_down(t_data *game, int rand);
static int	move_enemy_left_rigth(t_data *game, int rand);

int	enemy_loop(t_data *game)
{
	int	delay;
	int	random1;
	int	random2;

	find_enemies(game);
	game->loop++;
	random1 = (rand() % 2);
	random2 = (rand() % 2);
	if (random1 == 0)
		random1 = -1;
	delay = 5500;
	game->enemy = game->loop % delay;
	if (game->enemy == 0)
	{
		if (random2 == 0)
			move_enemy_left_rigth(game, random1);
		else if (random2 == 1)
			move_enemy_up_down(game, random1);
	}
	return (0);
}

void	find_enemies(t_data *game)
{
	int	row;
	int	col;

	game->enemy_num = 0;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'm')
			{
				game->enemy_x[game->enemy_num] = col;
				game->enemy_y[game->enemy_num] = row;
				game->enemy_num++;
			}
			col++;
		}
		row++;
	}
}

static int	move_enemy_left_rigth(t_data *game, int random)
{
	int	idx;

	idx = (rand() % 2);
	if (game->map[game->enemy_y[idx]][game->enemy_x[idx] + random] == '2')
	{
		put_image(game, game->floor_img, game->enemy_x[idx],
			game->enemy_y[idx]);
		game->map[game->enemy_y[idx]][game->enemy_x[idx]] = '2';
		game->enemy_x[idx] = game->enemy_x[idx] + random;
		game->map[game->enemy_y[idx]][game->enemy_x[idx]] = 'm';
		if (random < 0)
			put_image(game, game->enemy_img_left, game->enemy_x[idx],
				game->enemy_y[idx]);
		if (random > 0)
			put_image(game, game->enemy_img_right, game->enemy_x[idx],
				game->enemy_y[idx]);
	}
	else if (game->map[game->enemy_y[idx]][game->enemy_x[idx] + random] == 'P')
		end_game(game, "YOU LOOSE");
	return (0);
}

static int	move_enemy_up_down(t_data *game, int random)
{
	int	idx;

	idx = (rand() % 2);
	if (game->map[game->enemy_y[idx] + random][game->enemy_x[idx]] == '2')
	{
		put_image(game, game->floor_img, game->enemy_x[idx],
			game->enemy_y[idx]);
		game->map[game->enemy_y[idx]][game->enemy_x[idx]] = '2';
		game->enemy_y[idx] = game->enemy_y[idx] + random;
		game->map[game->enemy_y[idx]][game->enemy_x[idx]] = 'm';
		if (random < 0)
			put_image(game, game->enemy_img_up, game->enemy_x[idx],
				game->enemy_y[idx]);
		if (random > 0)
			put_image(game, game->enemy_img_down, game->enemy_x[idx],
				game->enemy_y[idx]);
	}
	else if (game->map[game->enemy_y[idx] + random][game->enemy_x[idx]] == 'P')
		end_game(game, "YOU LOOSE");
	return (0);
}
