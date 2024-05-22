/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:37:24 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/22 18:02:05 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define PLAYER_PATH "./img/player.xpm"
# define DOOR_PATH "./img/fish.xpm"
# define ENEMY_PATH "./img/monster_l1.xpm"
# define NUM_FRAMES 8
# define SIZE 32

typedef struct s_player_pos
{
	int				row;
	int				col;
}					t_player_pos;


typedef struct s_anim
{
	void 			*sprites[NUM_FRAMES];
	int				last_time;
	int				delay;
	int				current_frame;
}					t_anim;

typedef struct s_enemy
{
	int				step;
	int				direction;
	int				x;
	int				y;	
}	t_enemy;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				score;
	int				collectible_num;
	int				exit_num;
	int				player_num;
	int				moves;
	int				x;
	int				y;
	int				colls_num;
	int				row_num;
	int				player_direction;
	char			**map;
	void			*wall_img;
	void			*floor_img;
	void			*collectible_img;
	void			*door_img;
	void			*player_img;
	void			*enemy_img;
	t_player_pos	player_pos;
	t_anim			*anim;
	t_enemy			*enemy;
}					t_data;

// Graphics
int					init_map(char *map_path, t_data *game);
void				fill_map(t_data *game, int lines, char *map_path);
void				set_images(t_data *game);
void				print_map(char *line, t_data *game, int index);
void				add_graphics(t_data *game);
void				put_player(t_data *game, int width, int height);
void				put_image(t_data *game, void *image, int x, int y);

// check map
int					check_rectangle(t_data *game);
void				count_elements(t_data *game);
int					check_map(t_data *game);
int					check_around_map(t_data *game);
void				dfs_matrix(int x, int y, char **map);
int					valid_path(t_data *game);
int					check_char(t_data *game);
void				check_p_pos(t_data *game);
int					check_ber(char *argv, t_data *game);

// Moves and key hook
int					key_hook(int keysym, t_data *game);
void				update_player_move(t_data *game, int key);
void				move_top(t_data *game, int i, int j);
void				move_right(t_data *game, int i, int j);
void				move_left(t_data *game, int i, int j);
void				move_down(t_data *game, int i, int j);
void				door_locked_up_down(t_data *game, int door_row,
						int door_col);
void				door_locked_right_left(t_data *game, int door_row,
						int door_col);
void				print_foot(int key, t_data *game);

// Closing game
int					close_game(t_data *game);
void				free_map(t_data *game);
void				free_img(t_data *game);
int					error(char *str);

// Define
int					is_up(int key);
int					is_down(int key);
int					is_left(int key);
int					is_right(int key);
int					is_valid_char(int key);

// bonus
void				display_moves(t_data *game);
int				init_enemies(t_data *game);
int				anim_loop(t_data *game);

#endif
