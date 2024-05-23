/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:59:03 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 15:05:45 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*get_images(t_data *game, char *path)
{
	int		size;
	void	*img_addr;

	img_addr = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	if (img_addr == NULL)
		return (NULL);
	return (img_addr);
}
void	put_image(t_data *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * SIZE, y * SIZE);
}
void	set_images(t_data *game)
{
	game->floor_img = get_images(game, FLOOR_PATH);
	game->wall_img = get_images(game, WALL_PATH);
	game->collectible_img = get_images(game, COLL_PATH);
	game->door_img = get_images(game, DOOR_PATH);
	game->player_img_up = get_images(game, PLAYER_UP_PATH);
	game->player_img_down = get_images(game, PLAYER_DOWN_PATH);
	game->player_img_left = get_images(game, PLAYER_LEFT_PATH);
	game->player_img_right = get_images(game, PLAYER_RIGHT_PATH);
	game->enemy_img_up = get_images(game, ENEMY_UP_PATH);
	game->enemy_img_down = get_images(game, ENEMY_DOWN_PATH);
	game->enemy_img_left = get_images(game, ENEMY_LEFT_PATH);
	game->enemy_img_right = get_images(game, ENEMY_RIGHT_PATH);
}
static void	print_map(char *line, t_data *game, int index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			put_image(game, game->wall_img, i, index);
		else if (line[i] == '0' || line[i] == '2')
			put_image(game, game->floor_img, i, index);
		else if (line[i] == 'C' || line[i] == 'c')
			put_image(game, game->collectible_img, i, index);
		else if (line[i] == 'e')
			put_image(game, game->anim->sprites[game->anim->current_frame], i,
				index);
		else if (line[i] == 'P')
			put_player(game, i, index);
		else if (line[i] == 'M' || line[i] == 'm')
			put_image(game, game->enemy_img_down, i, index);
		i++;
	}
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
