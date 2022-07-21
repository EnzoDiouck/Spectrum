/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-01 11:20:48
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-01 11:20:49
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __BLIT_H__
#define __BLIT_H__

#include <lapin.h>

void std_blit(t_bunny_pixelarray *target, const t_bunny_pixelarray *src, const t_bunny_position *pos);

#endif /* __BLIT_H__ */