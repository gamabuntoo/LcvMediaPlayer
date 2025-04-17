#ifndef VLC_H
#define VLC_H

#include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ftprintf/ft_printf.h"

typedef struct 			s_val {
	int bpp;
	int size;
	int endian;
	char	*data;
	void	*img;
}				t_va;

typedef struct			s_tab {
	struct s_val	*img1;
	struct s_val	*img2;
}				t_tab;

typedef struct s_comp{
	double	x;
	double	y;
}				t_comp;


#endif

