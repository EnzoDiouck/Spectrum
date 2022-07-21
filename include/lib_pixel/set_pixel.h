/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:36
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __SETPIXEL_H__
#define __SETPIXEL_H__

#include <lapin.h>

void std_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);

#endif /* __SETPIXEL_H__ */