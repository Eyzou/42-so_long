/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:37:24 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/28 10:54:25 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

# define U 2
# define D 3
# define R 0
# define L 1

# define WALL_PATH "./img/wall.xpm"
# define FLOOR_PATH "./img/grass.xpm"
# define COLL_PATH "./img/carott.xpm"
# define PLAYER_UP_PATH "./img/player_up.xpm"
# define PLAYER_DOWN_PATH "./img/player_down.xpm"
# define PLAYER_LEFT_PATH "./img/player_left.xpm"
# define PLAYER_RIGHT_PATH "./img/player_right.xpm"
# define DOOR_PATH "./img/fish.xpm"
# define ENEMY_UP_PATH "./img/monster_u1.xpm"
# define ENEMY_DOWN_PATH "./img/monster_d1.xpm"
# define ENEMY_LEFT_PATH "./img/monster_l1.xpm"
# define ENEMY_RIGHT_PATH "./img/monster_r1.xpm"

# define NUM_FRAMES 6
# define SIZE 32

typedef struct s_player_pos
{
	int				row;
	int				col;
}					t_player_pos;

typedef struct s_anim
{
	void			*sprites[NUM_FRAMES];
	int				last_time;
	int				delay;
	int				current_frame;
}					t_anim;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				score;
	int				collectible_num;
	int				exit_num;
	int				player_num;
	int				enemy;
	int				enemy_num;
	int				enemy_x[256];
	int				enemy_y[256];
	int				moves;
	int				x;
	int				y;
	int				loop;
	int				colls_num;
	int				row_num;
	int				player_direction;
	char			**map;
	void			*wall_img;
	void			*floor_img;
	void			*collectible_img;
	void			*door_img;
	void			*player_img_up;
	void			*player_img_down;
	void			*player_img_right;
	void			*player_img_left;
	void			*enemy_img_up;
	void			*enemy_img_down;
	void			*enemy_img_right;
	void			*enemy_img_left;
	t_player_pos	player_pos;
	t_anim			*anim;
}					t_data;

// init
int		init_game(t_data *game, char **argv);
int		init_map(char *map_path, t_data *game);
int		init_mlx(t_data *game);
void	init_enemy(t_data *game);

// graphics
void	put_image(t_data *game, void *image, int x, int y);
void	*get_images(t_data *game, char *path);
void	set_images(t_data *game);
void	add_graphics(t_data *game);
void	put_player(t_data *game, int width, int height);

// check map
int		check_map(t_data *game);
int		valid_path(t_data *game);
void	count_elements(t_data *game);
void	check_ber(char *argv, t_data *game);

// Moves and key hook
int		key_hook(int keysym, t_data *game);
void	update_player_move(t_data *game, int key);
void	door_locked_up_down(t_data *game, int door_row,	int door_col);
void	door_locked_right_left(t_data *game, int door_row, int door_col);

// Closing game
int		close_game(t_data *game);
void	free_map(t_data *game);
void	free_img(t_data *game);
int		error(char *str);
int		end_game(t_data *game, char *str);

// Define
int		is_up(int key);
int		is_down(int key);
int		is_left(int key);
int		is_right(int key);
int		is_valid_char(int key);

// bonus
void	display_moves(t_data *game);
int		init_animation(t_data *game);
void	init_enemy(t_data *game);
int		combined_loop(t_data *game);
int		anim_loop(t_data *game);
int		enemy_loop(t_data *game);
void	find_enemies(t_data *game);

#endif
