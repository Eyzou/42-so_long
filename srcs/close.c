/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:24:52 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 16:47:09 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_img(t_data *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->door_img);
	mlx_destroy_image(game->mlx, game->player_img_up);
	mlx_destroy_image(game->mlx, game->player_img_down);
	mlx_destroy_image(game->mlx, game->player_img_left);
	mlx_destroy_image(game->mlx, game->player_img_right);
	mlx_destroy_image(game->mlx, game->enemy_img_up);
	mlx_destroy_image(game->mlx, game->enemy_img_down);
	mlx_destroy_image(game->mlx, game->enemy_img_left);
	mlx_destroy_image(game->mlx, game->enemy_img_right);
	while (i < NUM_FRAMES)
	{
		mlx_destroy_image(game->mlx, game->anim->sprites[i]);
		i++;
	}
}
int	close_game(t_data *game)
{
	free_map(game);
	free_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->anim);
	free(game);
	exit(0);
	return (0);
}

int	end_game(t_data *game, char *str)
{
	ft_printf("%s", str);
	close_game(game);
	exit(1);
}

int	error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}
