/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:20:48 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 17:50:50 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <time.h>

int	init_enemies(t_data *game)
{
	int	i;
	int	j;

	game->anim = ft_calloc(1, sizeof(t_anim));
	if (game->anim == NULL)
		exit(1);
	game->anim->last_time = 0;
	game->anim->current_frame = 0;
	game->anim->sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_l1.xpm", &i, &j);
	game->anim->sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_d2.xpm", &i, &j);
	game->anim->sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_l1.xpm", &i, &j);
	game->anim->sprites[3] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_l2.xpm", &i, &j);
	game->anim->sprites[4] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_r1.xpm", &i, &j);
	game->anim->sprites[5] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_r2.xpm", &i, &j);
	game->anim->sprites[6] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_u1.xpm", &i, &j);
	game->anim->sprites[7] = mlx_xpm_file_to_image(game->mlx,
			"./img/monster_u2.xpm", &i, &j);
	return (0);
}

int	anim_loop(t_data *game)
{
	int	current_time;

	current_time = clock();
	if (current_time - game->anim->last_time > 50000)
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

void	enemy_loop(t_data *game)
{
	int current_time;
	game->enemy->step =0;

	current_time = clock();
	if (current_time - game->anim->last_time > 5000)
	{
		add_graphics(game);
		display_moves(game);
		game->anim->last_time = current_time;
	}
}

/*int	patrol_loop(t_data *game)
{
	int current_time;

	current_time = clock();
	if (current_time - game->anim->last_time > 50000)
		{

			game->anim->current_frame++;
			if (game->anim->current_frame >= NUM_FRAMES)
				game->anim->current_frame = 0;
			game->anim->last_time = current_time;
			add_graphics(game);
			display_moves(game);
		}

	if(game->anim->sprites[game->anim->current_frame] == NULL)
			close_game(game);
	return(0);
}*/
