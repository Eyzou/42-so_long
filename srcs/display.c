/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:17:52 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/21 11:18:03 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void display_moves(t_data *game) 
{
    char *moves;
	char *msg;
	int	i;

	i = 0;
    moves = ft_itoa(game->moves);
	msg = ft_strjoin("Number of moves: ", moves);
	while(i < game->colls_num)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, i*32,0);
		i++;
	}
    mlx_string_put(game->mlx, game->win, 20, 20, 0xFFFFFF, msg);
    free(moves);
	free(msg);
}