/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:43:00 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 13:06:51 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_top(t_data *game, int i, int j);
static void	move_down(t_data *game, int i, int j);
static void	move_left(t_data *game, int i, int j);
static void	move_right(t_data *game, int i, int j);

void	update_player_move(t_data *game, int key)
{
	int	col;
	int	row;

	col = game->x;
	row = game->y;
	print_foot(key, game);
	if (is_down(key) && game->map[row + 1][col] != '1')
		move_top(game, col, row);
	if (is_up(key) && game->map[row - 1][col] != '1')
		move_down(game, col, row);
	if (is_right(key) && game->map[row][col + 1] != '1')
		move_right(game, col, row);
	if (is_left(key) && game->map[row][col - 1] != '1')
		move_left(game, col, row);
}

static void	move_top(t_data *game, int i, int j)
{
	game->player_direction = U;
	if (game->map[j + 1][i] == 'c')
		game->score += 1;
	else if (game->map[j + 1][i] == 'e' && game->collectible_num == game->score)
	end_game(game, "YOU WON!");
	else if (game->map[j + 1][i] == 'm')
		end_game(game, "YOU LOOSE!");
	else if (game->map[j + 1][i] == 'e')
	{
		door_locked_up_down(game, j + 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j + 1][i] = 'P';
	put_player(game, i, j + 1);
	put_image(game, game->floor_img, i, j);
}

static void	move_down(t_data *game, int i, int j)
{
	game->player_direction = D;
	if (game->map[j - 1][i] == 'c')
		game->score += 1;
	else if (game->map[j - 1][i] == 'e' && game->collectible_num == game->score)
		end_game(game, "YOU WON!");
	else if (game->map[j - 1][i] == 'm')
		end_game(game, "YOU LOOSE!");
	else if (game->map[j - 1][i] == 'e')
	{
		door_locked_up_down(game, j - 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j - 1][i] = 'P';
	put_player(game, i, j - 1);
	put_image(game, game->floor_img, i, j);
}

static void	move_left(t_data *game, int i, int j)
{
	game->player_direction = L;
	if (game->map[j][i - 1] == 'c')
		game->score += 1;
	else if (game->map[j][i - 1] == 'e' && game->collectible_num == game->score)
		end_game(game, "YOU WON!");
	else if (game->map[j][i - 1] == 'm')
		end_game(game, "YOU LOOSE!");
	else if (game->map[j][i - 1] == 'e')
	{
		door_locked_right_left(game, j, i - 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i - 1] = 'P';
	put_player(game, i - 1, j);
	put_image(game, game->floor_img, i, j);
}

static void	move_right(t_data *game, int i, int j)
{
	game->player_direction = R;
	if (game->map[j][i + 1] == 'c')
		game->score += 1;
	else if (game->map[j][i + 1] == 'e' && game->collectible_num == game->score)
		end_game(game, "YOU WON!");
	else if (game->map[j][i + 1] == 'm')
		end_game(game, "YOU LOOSE!");
	else if (game->map[j][i + 1] == 'e')
	{
		door_locked_right_left(game, j, i + 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i + 1] = 'P';
	put_player(game, i + 1, j);
	put_image(game, game->floor_img, i, j);
}
