/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:11 by ehamm             #+#    #+#             */
/*   Updated: 2024/03/28 16:59:01 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_elements(t_data *game)
{
	count_elements(game);
	if (game->collectible_num < 1 || game->player_num < 1 || game->exit_num < 1)
	{
		ft_printf("Error!\nSome elements of the game are missing\n");
		return (1);
	}
	if (game->player_num > 1 || game->exit_num > 1)
	{
		ft_printf("Error!\nThere is a doublon on the map\n");
		return (1);
	}
	return (0);
}

int	check_around_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->colls_num)
	{
		if (game->map[0][i] != '1')
			return (1);
		if (game->map[game->row_num - 1][i] != '1')
			return (1);
		i++;
	}
	if (game->colls_num < 3)
		return (1);
	j = 1;
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][game->colls_num - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_map(t_data *game)
{
	if (check_rectangle(game) == 1)
	{
		ft_printf("Error!\nThe map is not a rectangle!\n");
		return (1);
	}
	if (check_around_map(game) == 1)
	{
		ft_printf("Error!\nThe map should be surronded by trees-souches!\n");
		return (1);
	}
	if (check_elements(game) == 1)
		return (1);
	return (0);
}

void	dfs_matrix(int x, int y, char **map)
{
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return ;
	}
	if (is_valid(map[y][x + 1]))
		dfs_matrix(x + 1, y, map);
	if (is_valid(map[y][x - 1]))
		dfs_matrix(x - 1, y, map);
	if (is_valid(map[y + 1][x]))
		dfs_matrix(x, y + 1, map);
	if (is_valid(map[y - 1][x]))
		dfs_matrix(x, y - 1, map);
}

int	valid_path(t_data *game)
{
	int	i;
	int	j;

	check_p_pos(game);
	dfs_matrix(game->player[0], game->player[1], game->map);
	i = 0;
	while (i < game->row_num)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'e')
				return (0);
			j++;
		}
		i++;
	}
	ft_printf("Error!\nNo valid path in the map \n");
	return (1);
}
