/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:18:26 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 17:49:36 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_images(t_data *game)
{
	int	size;

	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &size,
			&size);
	if (game->floor_img == NULL)
		return ;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &size, &size);
	if (game->wall_img == NULL)
		return ;
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, COLL_PATH, &size,
			&size);
	if (game->collectible_img == NULL)
		return ;
	game->door_img = mlx_xpm_file_to_image(game->mlx, DOOR_PATH, &size, &size);
	if (game->door_img == NULL)
		return ;
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &size,
			&size);
	if (game->player_img == NULL)
		return ;
	game->enemy_img = mlx_xpm_file_to_image(game->mlx, ENEMY_PATH, &size,
			&size);
	if (game->enemy_img == NULL)
		return ;
}

void	check_p_pos(t_data *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'P')
			{
				game->player_pos.row = row;
				game->player_pos.col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	count_elements(t_data *game)
{
	int	row;
	int	col;

	game->collectible_num = 0;
	game->player_num = 0;
	game->exit_num = 0;
	row = 0;
	while (game->map[row])
	{
		col = 1;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'C')
				game->collectible_num++;
			if (game->map[row][col] == 'P')
				game->player_num++;
			if (game->map[row][col] == 'E')
				game->exit_num++;
			col++;
		}
		row++;
	}
}
