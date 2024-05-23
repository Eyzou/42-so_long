/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:20 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 14:35:27 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	dfs_matrix(int x, int y, char **map)
{
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y][x] == 'C')
		map[y][x] = 'c';
	if (map[y][x] == 'M')
		map[y][x] = 'm';
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return ;
	}
	if (is_valid_char(map[y][x + 1]))
		dfs_matrix(x + 1, y, map);
	if (is_valid_char(map[y][x - 1]))
		dfs_matrix(x - 1, y, map);
	if (is_valid_char(map[y + 1][x]))
		dfs_matrix(x, y + 1, map);
	if (is_valid_char(map[y - 1][x]))
		dfs_matrix(x, y - 1, map);
}

int	valid_path(t_data *game)
{
	int	row;
	int	col;

	dfs_matrix(game->player_pos.col, game->player_pos.row, game->map);
	row = 0;
	while (row < game->row_num)
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'C' || game->map[row][col] == 'E'
				|| game->map[row][col] == '0')
			{
				ft_printf("Error!\nNo valid path in the map \n");
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}


int	check_ber(char *argv, t_data *game)
{
	char	*ber_pos;

	ber_pos = ft_strnstr(argv, ".ber", ft_strlen(argv));
	if (ber_pos == NULL)
	{
		ft_printf("Error\nThe map is not a .ber file\n");
		free(game);
		return (1);
	}
	else if (ft_strlen(ber_pos) > 4)
	{
		ft_printf("Error\nThe map is not a .ber file\n");
		free(game);
		return (1);
	}
	// besoin de corriger case quand .ber only
	return (0);
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
