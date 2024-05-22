/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:59:03 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 18:18:02 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image(t_data *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * SIZE, y * SIZE);
}

void	add_graphics(t_data *game)
{
	int	i;

	i = 0;
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
			put_image(game, game->wall_img,i,index);
		else if (line[i] == '0' || line[i] == '2')
			put_image(game, game->floor_img,i,index);
		else if (line[i] == 'C' || line[i] == 'c')
			put_image(game, game->collectible_img,i,index);
		else if (line[i] == 'e')
			put_image(game, game->door_img,i,index);
		else if (line[i] == 'P')
			put_player(game, i, index);
		else if (line[i] == 'M'|| line[i] == 'm')
			put_image(game, game->anim->sprites[game->anim->current_frame],i,index);
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
	game->player_direction = 1;
	game->score = 0;
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
