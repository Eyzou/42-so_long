/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:20 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/21 10:26:51 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dfs_matrix(int x, int y, char **map)
{
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y][x] == 'C')
		map[y][x] = 'c';
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

	check_p_pos(game);
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

int	check_rectangle(t_data *game)
{
	int	col;
	int	row;

	row = 0;
	game->colls_num = ft_strlen(game->map[row]) - 1;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col] != '\0' && game->map[row][col] != '\n')
			col++;
		if (col != game->colls_num)
			return (1);
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

int	check_char(t_data *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col] != '\0' && game->map[row][col] != '\n'
			&& col < game->colls_num)
		{
			if (!is_valid_char(game->map[row][col])
				&& game->map[row][col] != '1')
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
