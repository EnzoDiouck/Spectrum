/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:33
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __SETLINE_H__
#define __SETLINE_H__

#include <lapin.h>

void std_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);
void std_set_line(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);

#endif /* __SETLINE_H__ */