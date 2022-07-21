/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-28 12:48:47
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-28 12:48:48
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __TEXT_H__
#define __TEXT_H__

#include <lapin.h>
#include <liblapin.h>

void std_letter(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, char c, unsigned int color);
void std_text(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, const char *str, unsigned int color);

#endif /* __TEXT_H__ */