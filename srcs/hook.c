/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:43:47 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/17 16:17:08 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keysym, t_data *game)
{
	if ((is_up(keysym)) || (is_down(keysym)))
		update_player_move(game, keysym);
	if ((is_right(keysym)) || (is_left(keysym)))
		update_player_move(game, keysym);
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}

void	update_player_move(t_data *game, int key)
{
	int	i;
	int	j;

	i = game->x;
	j = game->y;
	print_foot(key, game);
	if (is_down(key) && game->map[j + 1][i] != '1')
		move_top(game, i, j);
	if (is_up(key) && game->map[j - 1][i] != '1')
		move_down(game, i, j);
	if (is_right(key) && game->map[j][i + 1] != '1')
		move_right(game, i, j);
	if (is_left(key) && game->map[j][i - 1] != '1')
		move_left(game, i, j);
}

void	door_locked_up_down(t_data *game, int door_row, int door_col)
{
	if (game->player_position == U)
	{
		if (game->map[door_row + 1][door_col] == '1')
			return ;
		if (game->map[door_row + 1][door_col] == 'C')
			game->score += 1;
		game->map[door_row - 1][door_col] = '0';
		game->map[door_row + 1][door_col] = 'P';
		put_player(game, door_col, door_row + 1);
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, door_col
			* 32, (door_row - 1) * 32);
	}
	else if (game->player_position == D)
	{
		if (game->map[door_row - 1][door_col] == '1')
			return ;
		if (game->map[door_row - 1][door_col] == 'C')
			game->score += 1;
		game->map[door_row + 1][door_col] = '0';
		game->map[door_row - 1][door_col] = 'P';
		put_player(game, door_col, door_row - 1);
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, door_col
			* 32, (door_row + 1) * 32);
	}
}

void	print_foot(int key, t_data *game)
{
	int		i;
	int		j;
	int		moves;
	char	**map;

	map = game->map;
	moves = game->moves;
	i = game->x;
	j = game->y;
	if (is_down(key) && map[j + 1][i] != '1' && map[j + 1][i] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_up(key) && map[j - 1][i] != '1' && map[j - 1][i] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_right(key) && map[j][i + 1] != '1' && map[j][i + 1] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
	if (is_left(key) && map[j][i - 1] != '1' && map[j][i - 1] != 'e')
		ft_printf("tu as fait %i pas\n", moves);
}
