/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:43:00 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 17:03:46 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player(t_data *game, int col, int row)
{
	if (game->player_direction == U)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, col
			* 32, row * 32);
	else if (game->player_direction == D)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, col
			* 32, row * 32);
	else if (game->player_direction == L)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, col
			* 32, row * 32);
	else if (game->player_direction == R)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, col
			* 32, row * 32);
	game->x = col;
	game->y = row;
}

void	move_top(t_data *game, int i, int j)
{
	game->player_direction = U;
	if (game->map[j + 1][i] == 'c')
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
	game->player_direction = D;
	if (game->map[j - 1][i] == 'c')
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
	game->player_direction = L;
	if (game->map[j][i - 1] == 'c')
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
	game->player_direction = R;
	if (game->map[j][i + 1] == 'c')
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
