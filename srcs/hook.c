/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:43:47 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 14:44:27 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keysym, t_data *game)
{
	if ((is_up(keysym)) || (is_down(keysym)) || (is_right(keysym))
		|| (is_left(keysym)))
		update_player_move(game, keysym);
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}

void	put_player(t_data *game, int col, int row)
{
	if (game->player_direction == U)
		put_image(game,game->player_img_down, col,row);
	else if (game->player_direction == D)
		put_image(game,game->player_img_up, col,row);
	else if (game->player_direction == L)
		put_image(game,game->player_img_left, col,row);
	else if (game->player_direction == R)
		put_image(game,game->player_img_right, col,row);
	game->x = col;
	game->y = row;
}


void	door_locked_up_down(t_data *game, int door_row, int door_col)
{
	if (game->player_direction == U)
	{
		if (game->map[door_row + 1][door_col] == '1')
			return ;
		if (game->map[door_row + 1][door_col] == 'c')
			game->score += 1;
		game->map[door_row - 1][door_col] = '0';
		game->map[door_row + 1][door_col] = 'P';
		put_player(game, door_col, door_row + 1);
		put_image(game, game->floor_img, door_col, (door_row - 1));
	}
	else if (game->player_direction == D)
	{
		if (game->map[door_row - 1][door_col] == '1')
			return ;
		if (game->map[door_row - 1][door_col] == 'c')
			game->score += 1;
		game->map[door_row + 1][door_col] = '0';
		game->map[door_row - 1][door_col] = 'P';
		put_player(game, door_col, door_row - 1);
		put_image(game, game->floor_img, door_col, (door_row + 1));
	}
}

void	door_locked_right_left(t_data *game, int door_row, int door_col)
{
	if (game->player_direction == R)
	{
		if (game->map[door_row][door_col + 1] == '1')
			return ;
		if (game->map[door_row][door_col + 1] == 'c')
			game->score += 1;
		game->map[door_row][door_col - 1] = '0';
		game->map[door_row][door_col + 1] = 'P';
		put_player(game, door_col + 1, door_row);
		put_image(game, game->floor_img, (door_col -1), door_row);
	}
	else if (game->player_direction == L)
	{
		if (game->map[door_row][door_col - 1] == '1')
			return ;
		if (game->map[door_row][door_col - 1] == 'c')
			game->score += 1;
		game->map[door_row][door_col + 1] = '0';
		game->map[door_row][door_col - 1] = 'P';
		put_player(game, door_col - 1, door_row);
		put_image(game, game->floor_img, (door_col +1), door_row);
	}
}

