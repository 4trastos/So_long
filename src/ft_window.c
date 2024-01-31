/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:34:20 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/31 20:23:43 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../incl/game.h"

void	ft_window(char **map)
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
	img.img = mlx_new_image(mlx, 17 * 64, 8 * 64);
	img.wall = mlx_xpm_file_to_image(mlx, "textures/xpm/cono.xpm", &img.bits_per_pixel, &img.line_length);
	img.collect = mlx_xpm_file_to_image(mlx, "textures/xpm/escudo.xpm", &img.bits_per_pixel, &img.line_length);
	img.player = mlx_xpm_file_to_image(mlx, "textures/xpm/beniat.xpm", &img.bits_per_pixel, &img.line_length);
	j = 0;
	y = 0;
	while (j <= 1080 && y != 8)
	{
		x = 0;
		i = 0;
		while (i <= 1920 && x != 17)
		{
			if	(map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img.wall, i, j);
			else if	(map[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img.player, i, j);		
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img.collect, i, j);	
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
