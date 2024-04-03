/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:18:26 by ehamm             #+#    #+#             */
/*   Updated: 2024/03/29 14:50:05 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_images(t_data *game)
{
	int	i;
	int	j;

	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &i, &j);
	if (game->floor_img == NULL)
		return ;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &i, &j);
	if (game->wall_img == NULL)
		return ;
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, COLL_PATH, &i, &j);
	if (game->collectible_img == NULL)
		return ;
	game->door_img = mlx_xpm_file_to_image(game->mlx, DOOR_PATH, &i, &j);
	if (game->door_img == NULL)
		return ;
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &i, &j);
	if (game->player_img == NULL)
		return ;
}

void	check_p_pos(t_data *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player[0] = j;
				game->player[1] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	count_elements(t_data *game)
{
	int	i;
	int	j;

	game->collectible_num = 0;
	game->player_num = 0;
	game->exit_num = 0;
	i = 0;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectible_num++;
			if (game->map[i][j] == 'P')
				game->player_num++;
			if (game->map[i][j] == 'E')
				game->exit_num++;
			j++;
		}
		i++;
	}
}

int	check_rectangle(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	game->colls_num = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		while (game->map[i][j] && game->map[i][j] != '\n')
			j++;
		if (j != game->colls_num)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

void	check_ber(char *argv, t_data *game)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (argv[i] != '.')
		i++;
	i++;
	if (argv[i] != 'b')
		check++;
	i++;
	if (argv[i] != 'e')
		check++;
	i++;
	if (argv[i] != 'r')
		check++;
	if (check != 0)
	{
		ft_printf("Error\nThe map is not valid\n");
		free(game);
		exit(0);
	}
}
