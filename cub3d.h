#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <unisdt.h>
# include <stdlib.h>
# include <stdio.h>

# define FORWARD_W		119
# define BACK_S			115
# define RIGHT_D		100
# define LEFT_A			97
# define ROTATE_R
# define ROTATE_L
# define BUFFER_SIZE		4096
# define texH			64
# define texW			64
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	17

typedef struct	s_img
{
	void	*img;
	int	*data;
	int	size_l;
	int	endian;
	int	bpp;
	int	img_W;
	int	img_H;
}		t_img;

typedef struct	s_ray
{
	void	*mlx;
	void	*win;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	mvSpeed;
	double	rtSpeed;
	//
	t_img	img;
	int	**buf;
	int	**texture;

typedef struct	s_info
{
	int	save;
	int	error;
	// parsing
	int	inmap;
	int	F;
	int	C;
	int	RenderX;
	int	RenderY;
	char	*I;
	char	*N;
	char	*S;
	char	*W;
	char	*E;
	int	row;
	int	col;
	// parsing map
	char	**map;
	char	startNEWS;
	int	startX;
	int	startY;
	// struct
	t_ray	ray;
	int	num_spr;
}
/* parsing_line.c */
int	check_map_size(t_info *info, char *str);
int	resolution_color(t_info *info, char **str);
int	path_texture(t_info *info, char **texture, char *str);
int	parsing_line(t_info *info, char **str);

/* main.c */
int	check_map(t_info *info, char *arg);
int	check_save(t_info *info, char **arg);
int	parsing_elements(t_info *info, char *arg);
int	parsing_map(t_info *info, char *arg);

/* get_next_line */
int	get_next_line(t_info *info, int fd, char **line);

/* error.c */
void	ft_error(t_info *info, char *str);

#endif
/*
 * info->error
 * 0 : default
 * 1 : error and need to free gnl buff which is static variable
 *
 * the ft_error will end with exti(0) eventually
 */

