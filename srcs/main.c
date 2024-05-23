/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:15:41 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 16:43:08 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data *game;
	
	if (argc != 2)
		return (error("Error\nThe map is invalid\n"));
	game = calloc(1, sizeof(t_data));
	init_game(game,argv);
	init_mlx(game);
	init_animation(game);
	set_images(game);
	add_graphics(game);
	mlx_loop_hook(game->mlx, combined_loop, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

