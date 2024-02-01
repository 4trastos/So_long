/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:34:20 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/01 19:48:31 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_window(char **map, t_design *design)
{
	void	*mlx; //se llama en la struc game
	void	*mlx_win;
	t_data	img;
	int		y;
	int		x;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Beniat Txuri Urdina!!");
	img.grass = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, "textures/xpm/grass_01.xpm", &img.bits_per_pixel, &img.line_length);
	img.imgtwo = mlx_xpm_file_to_image(mlx, "textures/xpm/grass_02.xpm", &img.bits_per_pixel, &img.line_length);
	j = 0;
	while (j <= 1080)
	{
		i = 0;
		while (i <= 1920)
		{
			mlx_put_image_to_window(mlx, mlx_win, img.img, i, j);
			i = i + 64;
			if (i <= 1920)
			{
				mlx_put_image_to_window(mlx, mlx_win, img.imgtwo, i, j);
				i = i + 64;
			}
		}
		j = j + 64;
	}
//	img.img = mlx_new_image(mlx, 10 * 64, 18 * 64);
	img.img = mlx_new_image(mlx, design->columns * SIZE, design->rows * SIZE);
	img.wall = mlx_xpm_file_to_image(mlx, "textures/xpm/cono.xpm", &img.bits_per_pixel, &img.line_length);
	img.collect = mlx_xpm_file_to_image(mlx, "textures/xpm/escudo.xpm", &img.bits_per_pixel, &img.line_length);
	img.player = mlx_xpm_file_to_image(mlx, "textures/xpm/beniat.xpm", &img.bits_per_pixel, &img.line_length);
	img.exit = mlx_xpm_file_to_image(mlx, "textures/xpm/chapions.xpm", &img.bits_per_pixel, &img.line_length);
	j = 0;
	y = 0;
	while (j <= design->rows * SIZE && y != design->rows)
//	while (j <= 1080 * 64 && y != 10)
	{
		x = 0;
		i = 0;
		while (i <= design->columns * SIZE && x != design->columns)
//		while (i <= 1920 * 64 && x != 18)
		{
			if	(map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img.wall, i, j);
			else if	(map[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img.player, i, j);		
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img.collect, i, j);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img.exit, i, j);	
			i = i + 64;
			x++;
		}
		j = j + 64;
		y++;
    }
	mlx_loop(mlx);
}
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 65));
	*(unsigned int*)dst = color;
}*/
