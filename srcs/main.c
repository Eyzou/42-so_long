/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:15:41 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/21 14:13:45 by ehamm            ###   ########.fr       */
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
	init_enemies(game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (free(game->mlx),1);
	game->win = mlx_new_window(game->mlx, (game->colls_num) * 32,
			(game->row_num) * 32, "Elo RPG adventure");
	if (game->win == NULL)
		return (1);
	set_images(game);
	add_graphics(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
