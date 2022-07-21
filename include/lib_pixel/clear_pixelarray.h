/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:29
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __CLEARPIXEL_H__
#define __CLEARPIXEL_H__

#include <lapin.h>

void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);

void std_bunny_clear(t_bunny_pixelarray *px, unsigned int color);

#endif /* __CLEARPIXEL_H__ */
