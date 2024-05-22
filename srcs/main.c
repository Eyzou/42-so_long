/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:15:41 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 18:15:09 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return (error("Error\nThe map is invalid\n"));
	game = calloc(1, sizeof(t_data));
	if (init_map(argv[1], game) == 1 || check_ber(argv[1], game) == 1)
	{
		free_map(game);
		return (1);
	}
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (free(game->mlx), 1);
	game->win = mlx_new_window(game->mlx, (game->colls_num) * SIZE,
			(game->row_num) * SIZE, "Elo RPG adventure");
	if (game->win == NULL)
		return (1);
	init_enemies(game);
	set_images(game);
	add_graphics(game);
	mlx_loop_hook(game->mlx, anim_loop, game);
	// mlx_loop_hook(game->mlx,enemy_move,game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
