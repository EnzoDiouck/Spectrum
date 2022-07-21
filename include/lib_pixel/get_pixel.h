/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-28 12:25:39
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-28 12:25:54
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __GETPIXEL_H__
#define __GETPIXEL_H__

#include <lapin.h>

unsigned int std_get_pixel(const t_bunny_pixelarray *px, t_bunny_position pos);

unsigned int get_pixel(const t_bunny_pixelarray *px,
                       t_bunny_position pos);

#endif /* __GETPIXEL_H__ */
