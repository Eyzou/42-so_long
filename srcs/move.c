/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:43:00 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/17 16:16:44 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	door_locked_right_left(t_data *game, int door_row, int door_col)
{
	if (game->player_position == R)
	{
		if (game->map[door_row][door_col + 1] == '1')
			return ;
		if (game->map[door_row][door_col + 1] == 'C')
			game->score += 1;
		game->map[door_row][door_col - 1] = '0';
		game->map[door_row][door_col + 1] = 'P';
		put_player(game, door_col + 1, door_row);
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, (door_col
				- 1) * 32, door_row * 32);
	}
	else if (game->player_position == L)
	{
		if (game->map[door_row][door_col - 1] == '1')
			return ;
		if (game->map[door_row][door_col - 1] == 'C')
			game->score += 1;
		game->map[door_row][door_col + 1] = '0';
		game->map[door_row][door_col - 1] = 'P';
		put_player(game, door_col - 1, door_row);
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, (door_col
				+ 1) * 32, door_row * 32);
	}
}

void	move_top(t_data *game, int i, int j)
{
	game->player_position = U;
	if (game->map[j + 1][i] == 'C')
		game->score += 1;
	else if (game->map[j + 1][i] == 'e' && game->collectible_num == game->score)
	{
		ft_printf("YOUHOUUU you won the game! Well done kitty cat!\n");
		close_game(game);
	}
	else if (game->map[j + 1][i] == 'e')
	{
		door_locked_up_down(game, j + 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j + 1][i] = 'P';
	put_player(game, i, j + 1);
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 0 + i * 32, 0
		+ (j * 32));
}

void	move_down(t_data *game, int i, int j)
{
	game->player_position = D;
	if (game->map[j - 1][i] == 'C')
		game->score += 1;
	else if (game->map[j - 1][i] == 'e' && game->collectible_num == game->score)
	{
		ft_printf("YOUHOUUU you won the game! Well done kitty cat!\n");
		close_game(game);
	}
	else if (game->map[j - 1][i] == 'e')
	{
		door_locked_up_down(game, j - 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j - 1][i] = 'P';
	put_player(game, i, j - 1);
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 0 + i * 32, 0
		+ (j * 32));
}

void	move_left(t_data *game, int i, int j)
{
	game->player_position = L;
	if (game->map[j][i - 1] == 'C')
		game->score += 1;
	else if (game->map[j][i - 1] == 'e' && game->collectible_num == game->score)
	{
		ft_printf("YOUHOUUU you won the game! Well done kitty cat!\n");
		close_game(game);
	}
	else if (game->map[j][i - 1] == 'e')
	{
		door_locked_right_left(game, j, i - 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i - 1] = 'P';
	put_player(game, i - 1, j);
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 0 + i * 32, 0
		+ (j * 32));
}

void	move_right(t_data *game, int i, int j)
{
	game->player_position = R;
	if (game->map[j][i + 1] == 'C')
		game->score += 1;
	else if (game->map[j][i + 1] == 'e' && game->collectible_num == game->score)
	{
		ft_printf("YOUHOUUU you won the game! Well done kitty cat!\n");
		close_game(game);
	}
	else if (game->map[j][i + 1] == 'e')
	{
		door_locked_right_left(game, j, i + 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i + 1] = 'P';
	put_player(game, i + 1, j);
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 0 + i * 32, 0
		+ (j * 32));
}
