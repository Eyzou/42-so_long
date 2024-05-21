/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:59:03 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/21 14:11:23 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_graphics(t_data *game)
{
	int	i;

	i = 0;
	game->score = 0;
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
}

void	print_map(char *line, t_data *game, int index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_img, 0 + i
				* 32, 0 + (index * 32));
		else if (line[i] == '0' || line[i] == '2')
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 0 + i
				* 32, 0 + (index * 32));
		else if (line[i] == 'C' || line[i] == 'c')
			mlx_put_image_to_window(game->mlx, game->win, game->collectible_img,
				0 + i * 32, 0 + (index * 32));
		else if (line[i] == 'e')
			mlx_put_image_to_window(game->mlx, game->win, game->door_img, 0 + i
				* 32, 0 + (index * 32));
		else if (line[i] == 'P')
			put_player(game, i, index);
		else if (line[i] == 'E')
			enemy_animations(game);
		i++;
	}
}

void	fill_map(t_data *game, int lines, char *map_path)
{
	int	file;
	int	i;

	i = 0;
	file = open(map_path, O_RDWR);
	game->moves = 1;
	game->player_position = 1;
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
	if (file == -1)
	{
		ft_printf("Error!\nMap is invalid\n");
		return (1);
	}
	line = get_next_line(file);
	if (line == NULL)
		return (error("Error\nThe map is empty\n"));
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
