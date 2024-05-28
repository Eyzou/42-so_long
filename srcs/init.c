/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:03:12 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/28 12:28:01 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_data *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (free(game->mlx), 1);
	game->win = mlx_new_window(game->mlx, (game->colls_num) * SIZE,
			(game->row_num) * SIZE, "ELO RPG ADVENTURE");
	if (game->win == NULL)
		return (1);
	return (0);
}

int	init_game(t_data *game, char **argv)
{
	check_ber(argv[1], game);
	game->moves = 1;
	game->player_direction = 0;
	game->score = 0;
	game->colls_num = 0;
	game->row_num = 0;
	game->x = 0;
	game->y = 0;
	init_map(argv[1], game);
	return (0);
}

static void	fill_map(t_data *game, int lines, char *map_path)
{
	int	file;
	int	i;

	i = 0;
	file = open(map_path, O_RDWR);
	game->map = malloc(sizeof(char **) * (lines + 1));
	game->map[0] = get_next_line(file);
	while (i < lines)
	{
		i++;
		game->map[i] = get_next_line(file);
		game->row_num++;
	}
	if (check_map(game) == 1 || valid_path(game) == 1)
	{
		free_map(game);
		free(game);
		exit(EXIT_FAILURE);
	}
	close(file);
}

int	init_map(char *map_path, t_data *game)
{
	int		file;
	int		line_count;
	char	*line;

	line_count = 0;
	file = open(map_path, O_RDONLY);
	line = get_next_line(file);
	if (file == -1 || line == NULL)
	{
		free(game);
		return (error("Error\nMap is invalid\n"), 1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(file);
		line_count++;
	}
	close(file);
	fill_map(game, line_count, map_path);
	return (free(line), 0);
}
