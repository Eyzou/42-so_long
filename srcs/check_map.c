/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:11 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/18 18:36:13 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	/*if (check_char(game) == 1)
	{
		ft_printf("Error!\nInvalid character in the map\n");
		return (1);
	}*/
	if (check_elements(game) == 1)
		return (1);
	return (0);
}

void	dfs_matrix(int col, int row, char **map)
{
	if (map[row][col] == '0')
		map[row][col] = '2';
	if (map[row][col] == 'C')
		map[row][col] = 'c';
	if (map[row][col] == 'E')
	{
		map[row][col] = 'e';
		return ;
	}
	if (is_valid_char(map[row][col + 1]))
		dfs_matrix(col + 1, row, map);
	if (is_valid_char(map[row][col - 1]))
		dfs_matrix(col - 1, row, map);
	if (is_valid_char(map[row + 1][col]))
		dfs_matrix(col, row + 1, map);
	if (is_valid_char(map[row - 1][col]))
		dfs_matrix(col, row - 1, map);
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
			if (game->map[row][col] == 'C' || game->map[row][col] == 'E')
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

int check_ber(char *argv, t_data *game)
{

	char *ber_pos;
	ber_pos = ft_strnstr(argv,".ber",ft_strlen(argv));
	if(ber_pos == NULL)
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

/*int	check_char(t_data *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col] != '\0' && game->map[row][col] != '\n')
		{
			if (!is_valid_char(game->map[row][col]))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}*/