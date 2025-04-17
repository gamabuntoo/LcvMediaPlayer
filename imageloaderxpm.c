/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageloaderxpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:17:05 by gule-bat          #+#    #+#             */
/*   Updated: 2025/04/18 01:38:05 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ftprintf/ft_printf.h"
#include "vlc.h"

#define HEIGHT 1900
#define WIDTH 1500

t_tab	*copyimg(void	*srcimg, t_tab *tab, void	*mxptr)
{
	t_va	val;
	t_va	val2;
	
	tab = malloc(2 * sizeof(tab));
	val.bpp = 0;
	val.size = 0; 
	val.endian = 0;		
	val2.bpp = 0; 
	val2.size = 0; 
	val2.endian = 0;
	val.img = NULL;
	val2.img = mlx_new_image(mxptr, HEIGHT, WIDTH);
	val.data = mlx_get_data_addr(srcimg, &val.bpp, &val.size, &val.endian);
	val2.data = mlx_get_data_addr(val2.img, &val2.bpp, &val2.size, &val2.endian);
	tab->img1 = &val;
	tab->img2 = &val2;
	return (tab);
}

t_tab	*img_loader(char *path, void *mlx_ptr)
{
	void	*img;
	int	x;
	int y;
	x = 0;
	y = 0;
	t_tab *tab;
	
	tab = NULL;
	img = NULL;
	img = mlx_xpm_file_to_image(mlx_ptr, path, &x, &y);
	tab = copyimg(img, tab, mlx_ptr);
	if (!tab)
		return (printf("flop"), NULL);
	return (tab);
}



t_comp	vector_add(t_comp c1, t_comp c2)
{
	t_comp	result;

	result.x = (c1.x + c2.x);
	result.y = (c1.y + c2.y);
	return (result);
}

t_comp	comppower(t_comp z)
{
	t_comp	temp;

	temp.x = (z.x * z.x) - (z.y * z.y);
	temp.y = (2 * (z.x * z.y));
	return (temp);
}


int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	void	*mlx_ptr;
	void	*win_ptr;
	int	x = 0;
	int	y = 0;
	int o = 0;
	int l = 0;
	// t_tab	*tab;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "player");
	
	void *imgsrc;
	void *imgdst;
	imgsrc = mlx_xpm_file_to_image(mlx_ptr, argv[1], &x, &y);
	imgdst = mlx_new_image(mlx_ptr, x, y);
	
	t_va	val1;
	t_va	val2;
	t_comp	r1;
	t_comp	r2;
	val1.data = mlx_get_data_addr(imgsrc, &val1.bpp, &val1.size, &val1.endian);
	val2.data = mlx_get_data_addr(imgdst, &val2.bpp, &val2.size, &val2.endian);
	unsigned int g = 0;
	while (1)
{	
	int z = 0;
	int i = 0;
	// r1.x = map('x', x);
	// r1.y = map('y', y);
	// r2.x = map('x', o);
	// r2.y = map('y', l);
	o = 0;
	if (g > (sizeof (unsigned int))/2)
		g *= 1.618;
	else
		g = (g+1) * 2; ;
	while (o < y)
	{
		l = 0;
		r1 = vector_add(comppower(r1), comppower(r2));
		while (l < x)
		{
			if (o > (int)g)
				g -= o;
			i = o * val1.size + l * (val1.bpp) / 8;
			z = o * val2.size + l * (val2.bpp) / 8;
			// r2.x = map('x', i) / 2;
			// r2.y = map('y', z) / 2;
			r2 = vector_add(comppower(r2), comppower(r1));
			// if (l < val1.size/16)
			// if ((r2.x*r2.y) > o || (r2.x * r2.y) > o)
				// *(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i);
			if (o > l)
				*(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i)+(3*(g-(i*z))>>1);
			else if ((o < l || l < (int)g))
			{
				if (g % 2 == 0)
					*(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i)<<g--;
				else
					*(unsigned char *)(val2.data + z) = *(unsigned char *)(val1.data + i)>>(g++);
				// o--;
				// l = l + l ;
			}
			else
				*(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i)>>g;
			// if (o > l && g % 64)
				// l /= 4;
			// *(unsigned char *)(val2.data + z) = *(unsigned char *)(val1.data + i);
				// *(unsigned int *)(val2.data + 10 * val2.size + 10 * (val2.bpp / 8)) = val2.bpp>>1;
			// *(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i) * (r2.x+r2.y);
			l++;
		}
		// if (o < x/4)
		// else
		// *(unsigned int *)(val2.data + x) = *(unsigned int *)(val1.data + o)<<1;
		o++;
		if (o % 8 == 0)
		{
			
			mlx_put_image_to_window(mlx_ptr, win_ptr, imgdst, 50, 50);
			usleep(10000);
		}
	}
	// sleep(0.1);
	// mlx_destroy_image(mlx_ptr, win_ptr);
}
	mlx_loop(mlx_ptr);
}

// *(unsigned int *)(val2.data + z) = *(unsigned int *)(val1.data + i)<<1;