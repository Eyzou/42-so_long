/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:20:48 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/21 14:24:05 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemies(t_data *game)
{
	t_enemy	*enemy;
	enemy = game->enemy;
	enemy = ft_calloc(1, sizeof(t_enemy));
	if (enemy == NULL)
		exit(1);
	enemy->last_time = mlx_get_time();
	enemy->current_frame = 0;
	enemy->sprites[0] = "img/monster/monster_d1.xpm";
	enemy->sprites[1] = "img/monster/monster_d2.xpm";
	enemy->sprites[2] =	"img/monster/monster_l1.xpm";
	enemy->sprites[3] =	"img/monster/monster_l2.xpm";
	enemy->sprites[4] =	"img/monster/monster_r1.xpm";
	enemy->sprites[5] =	"img/monster/monster_r2.xpm";
	enemy->sprites[6] =	"img/monster/monster_u1.xpm";
	enemy->sprites[7] =	"img/monster/monster_u2.xpm";
}

void	enemy_animations(t_data *game)
{

	int current_time;
	
	current_time = mlx_get_time();

		if (current_time - game->anim->last_time > 200)
		{
			game->anim->current_frame++;
			if (game->anim->current_frame>=NUM_FRAMES)
				game->anim->current_frame = 0;
			game->anim->last_time = current_time;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->anim->sprites[game->anim->current_frame], game->anim->col
				* 32, game->anim->row * 32);
		if(game->anim->sprites[game->anim->current_frame] == NULL)
			close_game(game);
}


	