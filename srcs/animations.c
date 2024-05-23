/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:20:48 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/23 18:27:33 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <time.h>

int	init_animation(t_data *game)
{
	game->anim = ft_calloc(1, sizeof(t_anim));
	if (game->anim == NULL)
		exit(1);
	game->anim->last_time = 0;
	game->anim->current_frame = 0;
	game->anim->sprites[0] = get_images(game, "./img/door_01.xpm");
	game->anim->sprites[1] = get_images(game, "./img/door_02.xpm");
	game->anim->sprites[2] = get_images(game, "./img/door_1.xpm");
	game->anim->sprites[3] = get_images(game, "./img/door_2.xpm");
	game->anim->sprites[4] = get_images(game, "./img/door_3.xpm");
	game->anim->sprites[5] = get_images(game, "./img/door_4.xpm");
	return (0);
}

int	combined_loop(t_data *game)
{
	anim_loop(game);
	enemy_loop(game);
	return (0);
}

int	anim_loop(t_data *game)
{
	int	current_time;

	current_time = clock();
	if (current_time - game->anim->last_time > 600000)
	{
		game->anim->current_frame++;
		if (game->anim->current_frame >= NUM_FRAMES)
			game->anim->current_frame = 0;
		game->anim->last_time = current_time;
		add_graphics(game);
		display_moves(game);
	}
	if (game->anim->sprites[game->anim->current_frame] == NULL)
		close_game(game);
	return (0);
}
