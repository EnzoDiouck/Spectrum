/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-08 16:26:16
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-08 16:26:18
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <lapin.h>

void std_set_line(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);
void std_square(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);

#endif /* __SQUARE_H__ */